// a spanning tree is one which has n node and n-1 edges
// the tree with the least overall sum of weights of the edges is the MST
//prims help us find this weight and the edges used to get the weight


//time: O(E * logE), E is the no of edges
//space: O(E) + O(V)    
    //O(E) due to pq, and O(V) due to vis array and O(V-1) due to mst vector
    
#include <bits/stdc++.h>
using namespace std;

pair<int, vector<pair<int,int>>> prims(int src, const vector<vector<pair<int,int>>> &adj){
    int n = adj.size();
    priority_queue< pair<int, pair<int, int>>, vector< pair<int, pair<int,int>>>, greater< pair<int, pair<int, int>>>> pq;
    vector<bool> vis (n, false);

    vector<pair<int, int>> mst;
    int sum = 0;

    pq.push({0, {0, -1}}); // dist, node, parent

    while(!pq.empty()){
        int dist = pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;

        if(vis[node])continue;

        vis[node] = 1;
        sum += dist;
        if(parent != -1){
            mst.push_back({parent, node});
        }

        for(auto it: adj[node]){
            int wt = it.first;
            int adjNode = it.second;
            if( !vis[adjNode] ){
                pq.push({wt, {adjNode, node}});
            }
        }
    }

    return {sum, mst};
    
}

int main(){
    vector<vector<pair<int,int>>> adj;
    int src; //specify where do you wanna start from
    auto [sum, path] = prims(src, adj);
    return 0;
}