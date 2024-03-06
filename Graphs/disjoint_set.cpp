//Disjoint set & finding union by rank

//Time of union by rank and findParent: O(4 * alpha) almost = O(1)
//dont use union by size and rank together

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

int main(){
    DisjointSet ds(5);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(3,4);
    ds.unionByRank(3,5);

    //checking if 1 & 3 belong to the same component
    if(ds.findUPar(1) == ds.findUPar(3))        //write your logic on the same and diff parent
        cout<<"same\n";
    else cout<<"not same\n";

    return 0;
}
