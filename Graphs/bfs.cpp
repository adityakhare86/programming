#include <bits/stdc++.h>
using namespace std;

void bfs(int src, const vector<vector<int>> &adj, vector<bool> &vis){
    vis[src] = true;

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto nodes: adj[node]){
            if(!vis[nodes]){
                bfs(nodes, adj, vis);
            }
        }
    }
}

int main(){
    vector<vector<int>> adj;
    int n = adj.size();
    vector<bool> vis (n, false);
    for(int i=0; i<n; i++){
        if(!vis[i]){
            bfs(i, adj, vis);
        }
    }
    return 0;
}