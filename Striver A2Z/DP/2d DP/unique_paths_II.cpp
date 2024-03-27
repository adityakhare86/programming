/*
We are at (0, 0) and we have to reach (n-1, m-1) but there are some obstacles marked with
1 in the grid. We have to find the number of unique paths to reach (n-1, m-1).
*/

#include <bits/stdc++.h>
using namespace std;

class uniquePathsII{
private:
    int recursive_find(int x, int y, const vector<vector<int>> &obs){
        int n = obs.size(), m = obs[0].size();
        if(x >= n || y>= m || obs[x][y] == 1)return 0;
        if(x == n-1 && y == m-1)return 1;

        return recursive_find(x+1, y, obs) + recursive_find(x, y+1, obs);
    }

    int memoized_find(int x, int y, const vector<vector<int>> &obs, vector<vector<int>> &dp){
        int n = obs.size(), m = obs[0].size();
        if(x >= n || y>= m || obs[x][y] == 1)return 0;
        if(x == n-1 && y == m-1)return 1;
        if(dp[x][y] != -1)return dp[x][y];

        return dp[x][y] = memoized_find(x+1, y, obs, dp) + memoized_find(x, y+1, obs, dp);
    }
public:
    int reursion(vector<vector<int>>& obs) {
        return recursive_find(0, 0, obs);
    }

    int memoization(vector<vector<int>>& obs){
        int n = obs.size(), m = obs[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));

        return memoized_find(0, 0, obs, dp);
    }

    int tabulation(vector<vector<int>>& obs){
        int n = obs.size(), m = obs[0].size();
        vector<vector<int>> dp (n, vector<int> (m, 0));

        dp[0][0] = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(obs[i][j] == 1){
                    dp[i][j] = 0;
                }
                else{
                    if(j-1 >= 0)dp[i][j] += dp[i][j-1];
                    if(i-1 >= 0)dp[i][j] += dp[i-1][j];
                }
            }
        }

        return dp[n-1][m-1];
    }

    int spaceOpt(vector<vector<int>>& obs){
        int n = obs.size(), m = obs[0].size();

        vector<long long> dp (m, 0);
        for(int i=0; i<m; i++){
            if(obs[0][i] == 1)break;
            else dp[i] = 1;
        }


        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(obs[i][j] == 1)dp[j] = 0;
                else if(j > 0) dp[j] += dp[j-1];
            }
        }

        return dp[m-1];
    }
};