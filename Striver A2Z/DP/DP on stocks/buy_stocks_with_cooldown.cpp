#include <bits/stdc++.h>
using namespace std;

class StocksCooldown{
private:
    int recursive_find(int idx, vector<int> &prices){
        int n = prices.size();
        if(idx >= n)return 0;

        int temp_ans = 0;
        for(int i=idx+1; i<n; i++){
            temp_ans = max(temp_ans, prices[i] - prices[idx] + recursive_find(i+2, prices));
        }
        temp_ans = max(temp_ans, recursive_find(idx+1, prices));
        return temp_ans;
    }

    int memoized_find(int idx, const vector<int> &prices, vector<int> &dp){
        int n = prices.size();
        if(idx >= n)return 0;
        if(dp[idx] != -1)return dp[idx];

        int temp_ans = 0;
        for(int i=idx+1; i<n; i++){
            temp_ans = max(temp_ans, prices[i] - prices[idx] + memoized_find(i+2, prices, dp));
        }

        temp_ans = max(temp_ans, memoized_find(idx+1, prices, dp));
        return temp_ans;
    }
public:
    int recursion(vector<int> &prices){
        return recursive_find(0, prices);
    }

    int memoization(vector<int> &prices){
        int n = prices.size();
        vector<int> dp (n, -1);
        return memoized_find(0, prices, dp);
    }

    int tabulation(vector<int> &prices){
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int> (n+2, 0));

        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                dp[i][j] = max(dp[i+1][j], prices[j] - prices[i] + dp[j+2][j]);
            }
        }

        return dp[0][0];
    }
};