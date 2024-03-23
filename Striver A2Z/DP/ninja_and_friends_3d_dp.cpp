#include <bits/stdc++.h>
using namespace std;

class chocolatePickup{
private:
    bool isValid(int row, int col, int r, int c){
        return (row>=0 && row<r && col>=0 && col<c);
    }
    int recursive_find(int col1, int col2, int row, const vector<vector<int>> &grid){
        int r = grid.size(), c = grid[0].size();
        if(!isValid(row, col1, r, c) || !isValid(row, col2, r, c))return -1e9;
        if(row == r-1){
            if(col1 == col2)    
                return grid[row][col1];
            else
                return grid[row][col1] + grid[row][col2];
        }

        int maxi = -1e9;
        for(int delcol1 = -1; delcol1<2; delcol1++){
            for(int delcol2 = -1; delcol2<2; delcol2++){
                int newCol1 = col1 + delcol1;
                int newCol2 = col2 + delcol2;
                int ans;

                if(newCol1 == newCol2){
                    ans = grid[row][col1] + recursive_find(newCol1, newCol2, row+1, grid);
                }
                else{
                    ans = grid[row][col1] + grid[row][col2] + recursive_find(newCol1, newCol2, row+1, grid);
                }

                maxi = max(maxi, ans);  
            }
        }

        return maxi;
    }

    int memoized_find(int col1, int col2, int row, vector<vector<vector<int>>> &dp,
    const vector<vector<int>> &grid){
        int r = grid.size(), c = grid[0].size();
        if(!isValid(row, col1, r, c) || !isValid(row, col2, r, c))return -1e9;
        if(row == r-1){
            if(col1 == col2)    
                return grid[row][col1];
            else
                return grid[row][col1] + grid[row][col2];
        }
        if(dp[row][col1][col2] != -1)return dp[row][col1][col2];

        int maxi = -1e9;
        for(int delcol1 = -1; delcol1<2; delcol1++){
            for(int delcol2 = -1; delcol2<2; delcol2++){
                int newCol1 = col1 + delcol1;
                int newCol2 = col2 + delcol2;
                int ans;

                if(newCol1 == newCol2){
                    ans = grid[row][col1] + memoized_find(newCol1, newCol2, row+1, dp, grid);
                }
                else{
                    ans = grid[row][col1] + grid[row][col2] + memoized_find(newCol1, newCol2, row+1, dp, grid);
                }

                maxi = max(maxi, ans);  
            }
        }

        return dp[row][col1][col2] = maxi;
            
    }

public:
    int recursion(int r, int c, vector<vector<int>> &grid) {
        int col = grid[0].size();
        return recursive_find(0, col-1, 0, grid);
    }

    int memoization(int r, int c, vector<vector<int>> &grid){
        vector<vector<vector<int>>> dp (r, vector<vector<int>> (c, vector<int> (c, -1)));
        return memoized_find(0, c-1, 0, dp, grid);
    } 

    int tabulation(int r, int c, vector<vector<int>> &grid){
        vector<vector<vector<int>>> dp (r, vector<vector<int>> (c, vector<int> (c, -1)));

        for(int x1 = 0; x1<c; x1++){
            for(int x2 = 0; x2<c; x2++){
                if(x1 == x2)
                    dp[c-1][x1][x2] = grid[c-1][x1];
                else
                    dp[c-1][x1][x2] = grid[c-1][x1] + grid[c-1][x2];
            }
        }

        for(int i = r-2; i>=0; i--){
            for(int x1 = 0; x1<c; x1++){
                for(int x2 = 0; x2<c; x2++){
                    int maxi = INT_MIN;

                    for (int di = -1; di <= 1; di++) {
                        for (int dj = -1; dj <= 1; dj++) {
                            int ans;

                            if (x1 == x2)
                                ans = grid[i][x1];
                            else
                                ans = grid[i][x1] + grid[i][x2];

                            if ((j1 + di < 0 || x1 + di >= c) || (x2 + dj < 0 || x2 + dj >= c))
                                ans += -1e9;
                            else
                                ans += dp[i + 1][x1 + di][x2 + dj]; 

                            maxi = max(ans, maxi); 
                        }
                    }
                    dp[i][x1][x2] = maxi;
                }
            }
        }
    }
};