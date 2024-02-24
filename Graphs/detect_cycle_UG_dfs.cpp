#include <bits/stdc++.h>
using namespace std;

bool detectCycle(int src, int parent, vector<bool> &vis, const vector<vector<int>> &adj){
    vis[src] = 1;
    for(auto node: adj[src]){
        if(!vis[node]){
            if(detectCycle(node, src, vis, adj)) return true;
        }
        else if(parent != node)return true;
    }
    return false;
}

bool isCyclic(int n, const vector<vector<int>> &adj){
    vector<bool> vis (n, false);
    for(int i=0; i<n; i++){
        if(!vis[i]){
            if(detectCycle(i, -1, vis, adj)) return true;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> adj;
    int n = adj.size();
    bool cyclePresent = isCyclic(n, adj);
    return 0;
}