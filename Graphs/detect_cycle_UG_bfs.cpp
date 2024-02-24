#include <bits/stdc++.h>
using namespace std;

bool detectCycle(int src, vector<bool> &vis, const vector<vector<int>> &adj){
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});

    while(!q.empty()){
        int node = q.front().first, parent = q.front().second;
        q.pop();

        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = true;
                q.push({it, node});
            }
            else if(parent != it){
                return true;
            }
        }

        return false;
    }
}

bool isCyclic(int n, const vector<vector<int>> &adj){
    vector<bool> vis (n, false);
    for(int i=0; i<n; i++){
        if(!vis[i]){
            if(detectCycle(i, vis, adj)) return true;
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