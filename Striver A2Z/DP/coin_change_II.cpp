#include <bits/stdc++.h>
using namespace std;

class CoinChangeII{
private:
    int recursive_find(int idx, int leftOver, const vector<int> &coins){
        int n = coins.size();
        if(idx == n){
            if(leftOver == 0)return 1;
            return 0;
        }

        if(leftOver == 0)return 1;

        int take = 0;
        for(int coin = 0; leftOver - (coin * coins[idx]) >=0; coin++){
            take += recursive_find(idx+1, leftOver - (coin * coins  [idx]), coins);
        }

        return take;
    }

    int memoized_find(int idx, int leftOver, const vector<int> &coins, vector<vector<int>> &dp){
        int n = coins.size();
        if(idx == n){
            if(leftOver == 0)return 1;
            return 0;
        }
        if(leftOver == 0)return 1;
        if(dp[idx][leftOver] != -1)return dp[idx][leftOver];

        int take = 0;
        for(int coin = 0; leftOver - (coin * coins[idx]) >=0; coin++){
            take += memoized_find(idx+1, leftOver - (coin * coins  [idx]), coins, dp);
        }

        return dp[idx][leftOver] = take;
    }
public:
    int recursion(int amount, vector<int>& coins){
        return recursive_find(0, amount, coins);
    }

    int memoization(int amount, vector<int> &coins){
        int n = coins.size();
        vector<vector<int>> dp (n, vector<int> (amount+1, -1));
        return memoized_find(0, amount, coins, dp);
    }

    int tabulation(int mxAmt, vector<int> &coins){
        int n = coins.size();
        vector<vector<int>> dp (n, vector<int> (mxAmt+1, 0));

        for(int amt = 0; amt <= mxAmt; amt++){
            if(amt % coins[0] == 0)dp[0][amt] = 1;
        }

        for(int idx=1; idx<n; idx++){
            for(int amt=0; amt<=mxAmt; amt++){
                int take = 0;
                if(coins[idx] <= amt)take = dp[idx][amt - coins[idx]];
                int notTake = dp[idx-1][amt];

                dp[idx][amt] = take + notTake;
            }
        }

        return dp[n-1][mxAmt];
    }

    int spaceOpt(int mxAmt, vector<int> &coins){
        int n = coins.size();
        vector<int> dp1 (mxAmt+1, 0), dp2 (mxAmt+1, 0);

        for(int amt = 0; amt <= mxAmt; amt++){
            if(amt % coins[0] == 0)dp1[amt] = 1;
        }

        for(int idx=1; idx<n; idx++){
            for(int amt=0; amt<=mxAmt; amt++){
                int take = 0;
                if(coins[idx] <= amt)take = dp2[amt - coins[idx]];
                int notTake = dp1[amt];

                dp2[amt] = take + notTake;
            }

            dp1 = dp2;
            dp2.assign(mxAmt+1, 0);
        }

        return dp1[mxAmt];
    }
};