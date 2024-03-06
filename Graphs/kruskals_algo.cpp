//first sort the edges based on their edge weights
//starting from any node do a bfs and for nodes that do not belong to the same component
//make their parent same and add the edges weight to total weight
//also add the edge to mst vector

//time: O(N + E) for creating edges, N: nodes, E: edges
//      O(M * logM) for sorting edges, M: edges
//      O(M * 4 * alpha) for disjoint set on all edges

//space: O(N), N: no of nodes, due to size and rank

#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank, parent, size;
public: 
    DisjointSet(int n){
        rank.resize(n+1, 1);  //assuming 1 based indexing
        size.resize(n+1, 1);
        parent.resize(n+1);
        iota(parent.begin(), parent.end(), 0);
    }
    int findUPar(int node){ //find ultimate parent
        if(parent[node] != node)
            return node;
        return parent[node] = findUPar(parent[node]); //path compression
    }

    //union by rank basically connects the graph and returns the ultimate parent in O(1)
    //we attach the lower rank to the higher rank because the new height of the higher rank
    // is lesser as compared to when we attach higher rank to lower rank
    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v)return;
        if(rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if(rank[ulp_v] < rank[ulp_u])
            parent[ulp_v] = ulp_u;
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    //union by size: no of nodes in the component
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v])
            parent[ulp_u] = ulp_v;
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

pair<int, vector<pair<int,int>>> kruskals(int src, const vector<vector<pair<int,int>>> &adj){
    int n = adj.size();
    vector<pair<int, pair<int,int>>> edges;
    for(int i=0; i<n; i++){
        for(auto it: adj[i]){
            int adjNode = it.first;
            int wt = it.second;
            int node = i;

            edges.push_back({wt, {node, adjNode}}); //in case of UG we will pushing the same
            //edge twice but that won't affect the algo or its time complexity
            // as we don't go to nodes that have parent diff than themselves
        }
    }

    sort(edges.begin(), edges.end());

    DisjointSet ds(n+1); // 1 based indexing
    int sum = 0; vector<pair<int, int>> mst;
    for(auto it: edges){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(ds.findUPar(u) != ds.findUPar(v)){
            sum += wt;
            mst.push_back({u, v});
            ds.unionByRank(u, v);
        }
    }

    return {sum, mst};
}


int main(){
    vector<vector<pair<int,int>>> adj;
    int src; //specify the source, can be any though will give same ans
    auto [totalSum, mst] = kruskals(src, adj);
    return 0;
}