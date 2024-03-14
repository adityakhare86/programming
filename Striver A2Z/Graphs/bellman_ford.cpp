//the only difference between bellman and dijkstra is that
//bellman helps you to detect negative cycles
//bellman works only for directed graphs, so if you are given an undirected graph
//convert it to directed

//time complexity: V * E
#include <bits/stdc++.h>
using namespace std;


vector<int> bellman_ford(int src, int n, const vector<pair<int, pair<int, int>>> &edges){
    vector<int> dist (n, 1e9);
    dist[src] = 0;
    //doing relaxation n-1 times
    for(int i=0; i<n-1; i++){
        for(auto it: edges){
            int u = it.first;
            int v = it.second.first;
            int w = it.second.second;

            if(dist[u] != 1e9 && dist[u] + w < dist[v]){
                dist[v] = dist[v] = w;  
            }
        }
    }

    //nth relaxation
    for(auto it:edges){
        int u = it.first;
        int v = it.second.first;
        int w = it.second.second;

        if(dist[u] != 1e9 && dist[u] + w < dist[v]){
            return {-1}; ///returning -1 array if negative cycle is present
        }
    }

    return dist;
}

int main(){
    int m, src;
    cin>>src;
    cin >> m; // m is the number of edges

    //adjacency list for undirected graph
    //assuming 0 based indexing

    vector<pair<int, pair<int, int>>> edges;
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>> u>> v>> w;
        edges.push_back({u, {v, w}}); // from -> {to, src}
    }
    int n = edges.size();
    vector<int> ans = bellman_ford(src, n, edges);
    return 0;
}