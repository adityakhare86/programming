#include <bits/stdc++.h>
using namespace std;

void bfs(int node, vector<bool> &vis, stack<int> &st, const vector<vector<pair<int, int>>> &adj){
    vis[node] = 1;
    for(auto it: adj[node]){
        int v = it.first;
        if(!vis[v])bfs(v, vis, st, adj);
    }

    st.push(node);
}

stack<int> topoSort(int n, const vector<vector<pair<int, int>>> &adj){
    vector<bool> vis(n, false);
    stack<int> st;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            bfs(i, vis, st, adj);
        }
    }
}

vector<int> shortestPath(int node, stack<int> &st, const vector<vector<pair<int, int>>> &adj){
    int n = adj.size();
    vector<int> dist (n, 1e9);
    dist[node] = 0;

    while(!st.empty()){
        int node = st.top();
        st.pop();

        for(auto it: adj[node]){
            int v = it.first, wt = it.second;
            if(dist[node] + wt < dist[v]){
                dist[v] = dist[node] + wt;
            }
        }
    }

    return dist;
}

int main(){
    vector<vector<pair<int, int>>> adj; // pair because the it.second will contain weight
    int n = adj.size();
    stack<int> st = topoSort(n, adj);
    vector<int> dist = shortestPath(n, st, adj);
    return 0;
}