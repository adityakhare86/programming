#include <bits/stdc++.h>
using namespace std;

void dfs(int src, const vector<vector<int>> &adj, vector<bool> &vis, vector<int> &dfsList){
    vis[src] = true;
    dfsList.push_back(src);

    for(auto node: adj[src]){
        if(vis[node]){
            dfs(node, adj, vis, dfsList);
        }
    }
}

vector<int> dfsOfGraph(int n, const vector<vector<int>> &adj){
    vector<bool> vis(n, false);

    int src = 0; //from where we start traversal
    vector<int> dfsList;

    dfs(src, adj, vis, dfsList);

}

int main(){
    vector<vector<int>> adj;
    dfsOfGraph(adj.size(), adj);

    return 0;
}