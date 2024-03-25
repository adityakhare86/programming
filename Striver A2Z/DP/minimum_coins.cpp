#include <bits/stdc++.h>
using namespace std;

class MinimumCoins{
private:
    int recursive_find(int idx, int leftOver, const vector<int> &coins){
        int n = coins.size();
        if(idx == n){
            if(leftOver == 0)return 0;
            return 1e9;
        }
        if(leftOver == 0)return 0;

        int take = 1e9;
        for(int coin = 0; leftOver - (coin * coins[idx]) >=0; coin++){
            take = min(take, coin + recursive_find(idx+1, leftOver - (coin * coins[idx]), coins));
        }

        return take;
    }

    int memoized_find(int idx, int leftOver, const vector<int> &coins, vector<vector<int>> &dp){
        int n = coins.size();
        if(idx == n){
            if(leftOver == 0)return 0;
            return 1e9;
        }
        if(leftOver == 0)return 0;
        if(dp[idx][leftOver] != -1) return dp[idx][leftOver];

        int take = 1e9;
        for(int coin = 0; leftOver - (coin * coins[idx]) >=0; coin++){
            take = min(take, coin + memoized_find(idx+1, leftOver - (coin * coins[idx]), coins, dp));
        }

        return dp[idx][leftOver] = take;
    }

public:
    int recursion(vector<int> &coins, int amount){
        int ans = recursive_find(0, amount, coins);
        return ans == 1e9? -1: ans;
    }

    int memoization(vector<int> &coins, int amount){
        int n = coins.size();
        vector<vector<int>> dp (n, vector<int> (amount+1, -1));
        int ans = memoized_find(0, amount, coins, dp);
        return ans == 1e9? -1: ans;
    }

    int tabulation(vector<int> &coins, int mxAmt){
        int n = coins.size();
        vector<vector<int>> dp (n, vector<int> (mxAmt+1, 0));

        for(int amt = 0; amt <= mxAmt; amt++){
            if(amt % coins[0] == 0)
                dp[0][amt] = amt/coins[0];
            else
                dp[0][amt] = 1e9;
        }
        
        for(int denoms = 1; denoms<n; denoms++){
            for(int amt = 0; amt <= mxAmt; amt++){
                int notTake = dp[denoms-1][amt];
                int take = 1e9;
                if(coins[denoms] <= amt)
                    take = 1 + dp[denoms][amt - coins[denoms]];

                dp[denoms][amt] = min(take, notTake);
            }
        }


        return dp[n-1][mxAmt] >= 1e9? -1: dp[n-1][mxAmt];
    }

    int spaceOpt(vector<int> &coins, int mxAmt){
        int n = coins.size();
        vector<int> dp1 (mxAmt+1, 0), dp2 (mxAmt+1, 0);

        for(int amt = 0; amt <= mxAmt; amt++){
            if(amt % coins[0] == 0)
                dp1[amt] = amt/coins[0];
            else
                dp1[amt] = 1e9;
        }
        
        for(int denoms = 1; denoms<n; denoms++){
            for(int amt = 0; amt <= mxAmt; amt++){
                int notTake = dp1[amt];
                int take = 1e9;
                if(coins[denoms] <= amt)
                    take = 1 + dp2[amt - coins[denoms]];

                dp2[amt] = min(take, notTake);
            }
            dp1 = dp2;
            dp2.assign(mxAmt+1, 0);
        }


        return dp1[mxAmt] >= 1e9? -1: dp1[mxAmt];
    }
};