#include <bits/stdc++.h>
using namespace std;

bool isCyclic(int n, const vector<vector<int>> &adj){
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

    int count = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        count++;

        for(auto it: adj[node]){
            inDegree[it]--;
            if(inDegree[it] == 0)q.push(it);
        }
    }

    if(count == n)return false;
    return true;

}

int main(){
    vector<vector<int>> adj;
    int n = adj.size();
    bool cyclePresent = isCyclic(n, adj);
    return 0;
}