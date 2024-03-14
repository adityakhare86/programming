#include <bits/stdc++.h>
using namespace std;

void bfs(int src, const vector<vector<int>> &adj, vector<bool> &vis, vector<int> &bfsList)
{
    vis[src] = true;

    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfsList.push_back(node);

        for (auto nodes : adj[node])
        {
            if (!vis[nodes])
            {
                vis[nodes] = true;
                q.push(nodes);
            }
        }
    }
}

int main()
{
    vector<vector<int>> adj;
    // create adjacency as per need
    int n = adj.size();
    vector<bool> vis(n, false);
    vector<int> bfsList;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            bfs(i, adj, vis, bfsList);
        }
    }
    return 0;
}