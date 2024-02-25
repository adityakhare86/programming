#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int src, int n, const vector<vector<pair<int, int>>> &adj){
    vector<int> dist (n, 1e9);
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for(auto it: adj[node]){
            int wt = it.first;
            int adjNode = it.second;

            if(dis + wt < dist[adjNode]){
                dist[adjNode] = dis + wt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;

}

int main(){
    vector<vector<pair<int, int>>> adj;
    int n = adj.size();
    vector<int> ans = dijkstra(0, n, adj);
    return 0;
}