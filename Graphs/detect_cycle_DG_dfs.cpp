#include <bits/stdc++.h>
using namespace std;

bool detectCycle(int src, vector<bool> &vis, vector<bool> &pathVis, const vector<vector<int>> &adj){
    vis[src] = 1;
    pathVis[src] = 1; 

    for(auto node: adj[src]){
        if(!vis[node]){
            if(detectCycle(node, vis, pathVis, adj)) return true;
        }
        else if(pathVis[node])return true;
    }

    pathVis[src] = 0;
    return false;

}

bool isCyclic(int n, const vector<vector<int>> &adj){
    vector<bool> vis (n, false), pathVis (n, false);
    for(int i=0; i<n; i++){
        if(!vis[i]){
            if(detectCycle(i, vis, pathVis, adj)) return true;
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