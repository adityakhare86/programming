/*
We are at the (0,0) of a grid and we have to reach the (m-1, n-1) of it.
We need to return the minimum path sum of this.
*/

#include <bits/stdc++.h>
using namespace std;

class MinimumPathSum{
private:
    int recursive_find(int x, int y, int sum, const vector<vector<int>> &grid){
        int m = grid.size(), n = grid[0].size();
        if(x >= m || y>=n)return 1e9;
        if(x == m-1 && y == n-1)return sum + grid[x][y];

        return min(recursive_find(x+1, y, sum + grid[x][y], grid), recursive_find(x, y+1, sum + grid[x][y], grid));
    }

    int memoized_find(int x, int y, const vector<vector<int>> &grid, 
        vector<vector<int>> &dp){
        int m = grid.size(), n = grid[0].size();
        if(x == m-1 && y == n-1)return grid[x][y];
        if(x>=m || y>=n)return 1e9;
        if(dp[x][y] != -1) return dp[x][y];

        return dp[x][y] = min(memoized_find(x+1, y, grid, dp) + grid[x][y], 
            memoized_find(x, y+1, grid, dp) + grid[x][y]);
    }

public:
    int recursion(vector<vector<int>> grid){
        return recursive_find(0, 0, 0, grid);
    }

    int memoization(vector<vector<int>> &grid){
        vector<vector<int>> dp (grid.size(), vector<int> (grid[0].size(), -1));
        return memoized_find(0, 0, grid, dp);
    }

    int tabulation(vector<vector<int>> &grid){
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp (m, vector<int> (n, 1e9));

        dp[0][0] = grid[0][0];
        for(int i=1; i<m; i++)dp[i][0] = dp[i-1][0] + grid[i][0];
        for(int j=0; j<n; j++)dp[0][j] = dp[0][j-1] + grid[0][j];

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[m-1][n-1];
    }

    int spaceOpt(vector<vector<int>> &grid){
        int m = grid.size(), n = grid[0].size();
        vector<int> dp (n);

        dp[0] = grid[0][0];
        for(int i=1; i<n; i++){
            dp[i] = grid[0][i] + dp[i-1];
        }

        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                if(j==0)dp[j] += grid[i][j];
                else dp[j] = grid[i][j] + min(dp[j], dp[j-1]);
            }
        }

        return dp[n-1];
    }
};