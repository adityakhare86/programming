#include <bits/stdc++.h>
using namespace std;

class minTrianglePathSum{
private:
    int recursive_find(int x, int y, const vector<vector<int>> &triangle){
        int n = triangle.size(), m = triangle[x].size();
        if(x == n-1)return triangle[x][y];
        if(y >= m)return 1e9;

        return triangle[x][y] + min(recursive_find(x+1, y, triangle),
            recursive_find(x+1, y+1, triangle));
    }

    int memoized_find(int x, int y, vector<vector<int>> &dp, const vector<vector<int>> &triangle){
        int n = triangle.size(), m = triangle[x].size();
        if(x == n-1)return triangle[x][y];
        if(y >= m)return 1e9;
        if(dp[x][y] != -1)return dp[x][y];

        return dp[x][y] = triangle[x][y] + min(recursive_find(x+1, y, triangle),
            recursive_find(x+1, y+1, triangle));
    }
public:
    int recursion(vector<vector<int>> &triangle){
        return recursive_find(0, 0, triangle);
    }

    int memoizaton(vector<vector<int>> &triangle){
        int n = triangle.size();
        vector<vector<int>> dp (n, vector<int>());
        for(int i=0; i<n; i++){
            dp[i].resize(triangle[i].size(), -1);
        }

        return memoized_find(0, 0, dp, triangle);
    }

    int tabulation(vector<vector<int>> &triangle){
        int n = triangle.size();
        vector<vector<int>> dp (n, vector<int>());
        for(int i=0; i<n; i++){
            dp[i].resize(triangle[i].size(), -1);
        }

        dp[0][0] = triangle[0][0];

        for(int i=1; i<n; i++){
            int col = triangle[i].size();
            for(int j=0; j<col; j++){
                int up = 1e9, left = 1e9;
                if(j != col -1) up = dp[i-1][j];
                if(j != 0) left = dp[i-1][j-1];

                dp[i][j] = triangle[i][j] + min(up, left);
            }
        }

        return dp[n-1][dp[n-1].size()-1];
    }

    int spaceOpt(vector<vector<int>> &triangle){
        int n = triangle.size(), m = triangle[n-1].size();
        vector<int> dp1 (m, -1), dp2 (m, -1);
        dp1[0] = triangle[0][0];

        for(int i=1; i<n; i++){
            int col = triangle[i].size();
            for(int j=0; j<col; j++){
                int up = 1e9, left = 1e9;
                if(j != col-1) up = dp1[j];
                if(j != 0)left = dp1[j-1];
                dp2[j] = triangle[i][j] + min(up, left);
            }
            dp1 = dp2;
            dp2.assign(m, -1);
        }

        int ans = 1e9;
        for(auto it: dp1)ans = min(ans, it);
        return ans;
    }
};