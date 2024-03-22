#include <bits/stdc++.h>
using namespace std;

class UniquePaths {
private:
    int recursive_find(int x, int y, int m, int n){
        if(x==m-1 && y==n-1)return 1;
        if(x>=m || y>=n)return 0;

        return recursive_find(x+1, y, m, n) + recursive_find(x, y+1, m, n);
    }

    int memoized_find(int x, int y, int m, int n, vector<vector<int>> &dp){
        if(x==m-1 && y==n-1)return 1;
        if(x>=m || y>=n)return 0;
        if(dp[x][y] != -1)return dp[x][y];

        return dp[x][y] = memoized_find(x+1, y, m, n, dp) + memoized_find(x, y+1, m, n, dp);
    }

    bool isValid(int x, int y, int m, int n){
        return (x>=0 && x<m && y>=0 && y<n);
    }
public:
    int recursion(int m, int n) {
        return recursive_find(0, 0, m, n);
    }

    int memoization(int m, int n){
        vector<vector<int>> dp (m, vector<int> (n, -1));
        return memoized_find(0, 0, m, n, dp);
    }

    int tabulation(int m, int n){
        vector<vector<int>> dp (m, vector<int> (n, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isValid(i-1, j, m, n))dp[i-1][j] += dp[i-1][j];
                if(isValid(i, j-1, m, n))dp[i][j-1] += dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }

    int spaceOpt(int m, int n){
        vector<int> dp (n, 1);

        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                if(j-1 >=0) dp[j] += dp[j-1];
            }
        }

        return dp[n-1];
    }
};