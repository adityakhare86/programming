/*
we use kosaraju to find strongly connected components (SCCs)

let there are two nodes in SCC, A and B, then A must be able to reach B
and B must be able to reach A

A single node is also a SCC

To go from one SCC to another there is a node, which if reversed we find
that we cannot reach the another SCC

Following the same idea we reverse the nodes of the entire graph and keep
a track of nodes that we have traversed

we keep track before while traversing we traverse the nodes of scc first then 
another and so on

so after reversing the nodes we will only be able to traverse the nodes of one
component at a time

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj, st);
            }
        }

        st.push(node);
    }

    void dfs_rev(int node, vector<int> &temp, vector<int> &vis, vector<vector<int>> &adj_rev){
        vis[node] = 1;
        temp.push_back(node);
        for(auto it: adj_rev[node]){
            if(!vis[it]){
                dfs_rev(it, temp, vis, adj_rev);
            }
        }
    }

public:
    vector<vector<int>> kosaraju(int n, vector<vector<int>> adj){
        vector<int> vis (n, 0);
        stack<int> st;
        for(int i=0; i<n; i++){
            if(!vis[i]) dfs(i, vis, adj, st);
        }

        vector<vector<int>> adj_rev;
        for(int i=0; i<n; i++){
            vis[i] = 0;
            for(auto it: adj[i]){
                adj_rev[it].push_back(i);
            }
        }

        vector<vector<int>> scc;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                vector<int> temp;
                dfs_rev(node, temp, vis, adj_rev);
                scc.push_back(temp);
            }
        }

        return scc;
    }
};