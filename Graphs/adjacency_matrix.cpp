#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    // adjacency for undirected
    //assuming 0 based indexing
    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    //adjacency for directed
    //directed from u to v
    vector<vector<int>> adj (n);
    for(int i=0; i<m; i++){
        int u, v;
        cin>> u>> v;
        adj[u][v] = 1;
    }

    return 0;
}