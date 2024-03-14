#include <bits/stdc++.h>
using namespace std;

//topo sorting using bfs is also known as kahn's algo
vector<int> topoSort(int n, const vector<vector<int>> &adj){
    vector<int> inDegree (n, 0);
    for(int i=0; i<n; i++){
        for(auto node: adj[i]){
            inDegree[node]++;
        }
    }

    queue<int> q;
    for(int i=0; i<n; i++){
        if(inDegree[i] == 0)q.push(i);
    }

    vector<int> topoList;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        topoList.push_back(node);
        for(auto it: adj[node]){
            inDegree[it]--;
            if(inDegree[it]==0)q.push(it);
        }
    }

    return topoList;
}

int main(){
    vector<vector<int>> adj;
    int n = adj.size();
    vector topoList = topoSort(n, adj);
    return 0;
}