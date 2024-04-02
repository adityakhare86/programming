#include <bits/stdc++.h>
using namespace std;

class StocksIII{
private:
    int recursive_find(int idx, int txns, const vector<int> &prices){
        int n = prices.size();
        if(idx == n)return 0;
        if(txns == 0)return 0;

        int temp_ans = 0;
        for(int i=idx+1; i<n; i++){
            if(prices[i] > prices[idx]){
                temp_ans = max(temp_ans, prices[i] - prices[idx] + recursive_find(i+1, txns-1, prices));
            }
        }
        temp_ans = max(temp_ans, recursive_find(idx+1, txns, prices));

        return temp_ans;
    }

    int memoized_find(int idx, int txns, const vector<int> &prices, vector<vector<int>> &dp){
        int n = prices.size();
        if(idx >= n || txns == 0)return 0;
        if(dp[txns][idx] != -1)return dp[txns][idx];

        int temp_ans = 0;
        for(int i=idx+1; i<n; i++){
            if(prices[i] > prices[idx]){
                temp_ans = max(temp_ans, prices[i] - prices[idx] + memoized_find(i+1, txns-1, prices, dp));
            }
        }

        temp_ans = max(temp_ans, memoized_find(idx+1, txns, prices, dp));

        return dp[txns][idx] = temp_ans;
    }

public:
    int recursion(vector<int> &prices){
        return recursive_find(0, 2, prices);
    }

    int memoization(vector<int> &prices){
        int n = prices.size();
        vector<vector<int>> dp (3, vector<int> (n, -1)) ;
        return memoized_find(0, 2, prices, dp);
    }
    
    int tabulation(vector<int> &prices){
        int n = prices.size();
        vector<vector<int>> dp (3, vector<int> (n+1, 0));
        
        int n = prices.size();
        int k = 2; 

        vector<vector<int>> dp(k + 1, vector<int>(n, 0));

        //maxDiff is the total profit after buying
        //dp[i][j] is the total profit of max(if i sell on that day, profit on prev day)
        for (int txn = 1; txn <= k; txn++) {
            int maxDiff = -prices[0];
            for (int day = 1; day < n; day++) {
                dp[txn][day] = max(dp[txn][day - 1], prices[day] + maxDiff);
                maxDiff = max(maxDiff, dp[txn - 1][day] - prices[day]);
            }
        }

        return dp[k][n - 1];
    }
};