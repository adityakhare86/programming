/* articulation point -> node in a graph that breaks the component
into one or more components 

we follow the same approach as tarjan's algo difference being we don't
update the low when we find "visited nodes" or parent node

the exception from targan algo is how we handle edge for parent node
if parent node has more than one children then we mark it as a articulation
point

we have added the case for visited because we want to find a path except from 
the path that we came (path marked by visited nodes) to reach our parent node.
If there is any such path then the parent is not a articulation point.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    int timer = 0;
    void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, 
    vector<int> &low, vector<int> &mark, vector<vector<int>> &adj){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        int child = 0;

        for(auto it: adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(it, node, vis, tin, low, mark, adj);
                low[node] = min(low[node], low[it]);
                if(low [it] >= tin[node && parent != -1]){
                    mark[node] = 1;
                }
                child++;
            }
            else{
                low[node] = min(low[node], low[it]);
            }
        }

        if(child > 1 && parent == -1){
            mark[node] = 1;
        }
    }
public:
    vector<int> articulation_point(int n, vector<vector<int>> adj){
        vector<int> tin (n), low(n), mark(n, 0), vis(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[n]) dfs(i, -1, vis, tin, low, mark, adj);
        }

        vector<int> ans;
        for(int i=0; i<n; i++){
            if(mark[i]){
                ans.push_back(i);
            }
        }

        if(ans.size() == 0)return {-1};
        return ans;
    }

};