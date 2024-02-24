#include <bits/stdc++.h>
using namespace std;

void dfs(int src, vector<bool> &vis, stack<int> &st, const vector<vector<int>> &adj){
    vis[src] = true;
    for(auto node: adj[src]){
        if(!vis[node]) dfs(node, vis, st, adj);
    }

    st.push(src);
}

vector<int> topoSort(int n, const vector<vector<int>> &adj){
    vector<bool> vis(n);
    stack<int> st;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i, vis, st, adj);
        }
    }

    vector<int> topoList;
    while(!st.empty()){
        topoList.push_back(st.top());
        st.pop();
    }

    return topoList;
}

int main(){
    vector<vector<int>> adj;
    int n = adj.size();
    vector<int> topoList = topoSort(n, adj);
    return 0;
}