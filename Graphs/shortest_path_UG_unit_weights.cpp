#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int src, int n, const vector<vector<int>> &adj){
    vector<int> dist (n, 1e9);
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it: adj[node]){
            if(dist[node] + 1 < dist[it]){
                dist[it] = 1 + dist[node];
                q.push(it);
            }
        }
    }

    vector<int> ans (n, -1);
    for(int i=0; i<n; i++){
        if(dist[i] != 1e9){
            ans[i] = dist[i];
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> adj;
    int n = adj.size();
    vector<int> ans = shortestPath(0, n, adj);
    return 0;
}