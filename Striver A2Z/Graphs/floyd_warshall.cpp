//tells shortest path from every node to every other node
//also detects negative cycles
//Time complexity: O(n^3)
//Space comlexity: O(n^2)

//One could also use dijkstra if the graph doesn't have negative cycle
//they would just have to apply dijkstra on every node which would take:
//O(V * (E * log(v))), which is lesser than O(n^3)

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void floyd_warshall(vector<vector<int>> &matrix){
        int n= matrix.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == -1)matrix[i][j] = 1e9;
                if(i==j) matrix[i][j] = 0;
            }
        }
        
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 1e9)matrix[i][j] = -1;
            }
        }
    }
};

int main(){
    int n; cin>>n;
    vector<vector<int>> matrix (n, vector<int> (n, -1));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>matrix[i][j];
        }
    }

    Solution obj;
    obj.floyd_warshall(matrix);
    return 0;
}