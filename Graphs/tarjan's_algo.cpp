//this is the solution for LeetCode question "Critical connections in a network"
//the intuition is that if children of node that called the dfs can be reached from node
//other than parent then the connection between the parent and child in not a critical connection
//which if removed would result breaking of graph into components + 1

//we aim to implement this by keeping a global timer which helps to mark 
//the time at which every node was visited and stores it in tin
//the low vector keeps track of the lowest time in which the node can be visited

//if a child node has higher in time than lowest time of parent then it is a critical
//connection

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, int parent, vector<bool> &vis, vector<vector<int>> &adj,
    vector<int> &tin, vector<int> &low, vector<vector<int>> &bridges){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        for(auto it: adj[node]){
            if(it == parent)continue;
            if(vis[it] == 0){
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[node], low[it]);
                if(low[it] > tin[node]) bridges.push_back({it, node});
            }
            else{
                low[node] = min(low[node], low[it]);
            }
        }
    }
public:
    int timer = 1;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) {
        vector<vector<int>> adj (n);

        for(int i=0; i<conn.size(); i++){
            adj[conn[i][0]].push_back(conn[i][1]);
            adj[conn[i][1]].push_back(conn[i][0]);
        }

        vector<bool> vis (n, false);
        vector<int> tin (n), low (n);
        vector<vector<int>> bridges;

        dfs(0, -1, vis, adj, tin, low, bridges);
        return bridges;
    }
};