#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int src, int n, const vector<vector<pair<int, int>>> &adj){
    set<pair<int, int>> s;
    vector<int> dist (n, 1e9);

    s.insert({0, src});
    dist[src] = 0;

    while(!s.empty()){
        int node = (s.begin())->second;
        int wt = (s.begin())->first;
        s.erase(s.begin());

        for(auto it: adj[node]){
            int edgeWt = it.second; 
            int adjNode = it.first;
            if(wt + dist[node] < dist[adjNode]){
                if(dist[adjNode] != 1e9){
                    s.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = dist[node] + wt;
                s.insert({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

int main(){
    vector<vector<pair<int,  int>>> adj;
    int n = adj.size();
    vector<int> ans = dijkstra(0, n, adj);
    return 0;
}