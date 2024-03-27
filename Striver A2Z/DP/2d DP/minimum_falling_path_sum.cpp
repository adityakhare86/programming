#include <bits/stdc++.h>
using namespace std;

class MinFallingPathSum{
private:
    bool isValid(int x, int y, int n){
        return (x>=0 && x<n && y>=0 && y<n);
    }
    int recursive_find(int x, int y, vector<vector<int>> &matrix){
        int n = matrix.size();
        if(!isValid(x, y, n))return 1e9;
        if(y == n-1)return matrix[x][y];

        int down = recursive_find(x + 1, y, matrix);
        int down_left = recursive_find(x + 1, y - 1, matrix);
        int down_right = recursive_find(x + 1, y + 1, matrix);

        return matrix[x][y] + min({down, down_left, down_right});
    }

    int memoized_find(int x, int y, vector<vector<int>> &dp, 
    const vector<vector<int>> &matrix){
        int n = matrix.size();
        if(!isValid(x, y, n))return 1e9;
        if(x == n-1)return matrix[x][y];
        if(dp[x][y] != 1e9)return dp[x][y];

        int down = memoized_find(x + 1, y, dp, matrix);
        int down_left = memoized_find(x + 1, y - 1, dp, matrix);
        int down_right = memoized_find(x + 1, y + 1, dp, matrix);

        return dp[x][y] = matrix[x][y] + min({down, down_left, down_right});
    }
public:
    int recursion(vector<vector<int>> &matrix){
        int n = matrix.size() ,ans = 1e9;
        for(int i=0; i<n; i++){
            ans = min(ans, recursive_find(0, i, matrix));
        }
        return ans;
    }

    int memoization(vector<vector<int>> &matrix){
        int n = matrix.size(), ans = 1e9;
        vector<vector<int>> dp (n, vector<int> (n, 1e9));

        for(int i=0; i<n; i++){
            ans = min(ans, memoized_find(0, i, dp, matrix));
        }

        return ans;
    }
    
    int tabulation(vector<vector<int>> &matrix){
        int n = matrix.size();
        vector<vector<int>> dp (n, vector<int> (n, 1e9));

        dp[0] = matrix[0];

        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int up = dp[i-1][j], upLeft = 1e9, upRight = 1e9;
                if(j != 0) upLeft = dp[i-1][j-1];
                if(j != n-1) upRight = dp[i-1][j+1];
                dp[i][j] = matrix[i][j] + min({up, upLeft, upRight});
            }
        }

        int ans = 1e9;
        for(int i=0; i<n; i++){
            ans = min(ans, dp[n-1][i]);
        }

        return ans;
    }

    int spaceOpt(vector<vector<int>> &matrix){
        int n = matrix.size();
        vector<int> dp1 (n, 1e9), dp2 (n, 1e9);
        dp1 = matrix[0];

        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int up = dp1[j], upLeft = 1e9, upRight = 1e9;
                if(j != 0) upLeft = dp1[j-1];
                if(j != n-1) upRight = dp1[j+1];

                dp2[j] = matrix[i][j] + min({upLeft, up, upRight});
            }
            dp1 = dp2;
            dp2.assign(n, 1e9);
        }

        int ans = 1e9;
        for(auto ele: dp1) ans = min(ans, ele);
        return ans;
    }
};