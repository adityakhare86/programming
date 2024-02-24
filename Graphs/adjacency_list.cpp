#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m; // m is the number of edges

    //adjacency list for undirected graph
    //assuming 0 based indexing

    vector<vector<int>> adj (n);
    for(int i=0; i<m; i++){
        int u, v;
        cin>> u>> v;
        adj[u].push_back(u);
        adj[v].push_back(v);
    }

    //for directed remove one of the push backs, as per the direction 
    return 0;
}
