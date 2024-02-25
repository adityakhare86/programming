#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int src, int dst, int n, const vector<vector<pair<int, int>>> &adj){
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    vector<int> dist (n, 1e9);
    vector<int> parent (n);
    iota(parent.begin(), parent.end(), 0);

    pq.push({0, src});
    dist[src] = 0;
    
    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adj[node]){
            int edgeWt = it.second;
            int adjNode = it.first;
            if(dis + edgeWt < dist[adjNode]){
                dist[adjNode] = dis + edgeWt;
                pq.push({dis + edgeWt, adjNode});
                parent[adjNode] = node;
            }
        }
    }
        if(dist[src] == 1e9)return {-1};

        vector<int> path;
        int node = n; 
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(node);
        reverse(path.begin(), path.end());

        return path;
}

int main(){
    vector<vector<pair<int,int>>> adj;
    int n = adj.size();
    int src = 0, dst = n-1;
    vector<int> ans = shortestPath(src, dst, n, adj);
    return 0;
}