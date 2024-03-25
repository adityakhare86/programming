#include <bits/stdc++.h>
using namespace std;

class Knapsack01{
private:
    int recursive_find(int idx, int currWeight, const vector<int> &weight,
        const vector<int> &value, int maxWeight){
            int n = weight.size();
            if(idx == n)return 0;

            int take = 0;
            if(weight[idx] + currWeight <=maxWeight) 
                take = value[idx] + recursive_find(idx+1, currWeight + weight[idx], weight, value, maxWeight);
            int notTake = recursive_find(idx+1, currWeight, weight, value, maxWeight);

            return max(take, notTake);
        }

    int memoized_find(int idx, int currWeight, const vector<int> &weight, 
        const vector<int> &value, int maxWeight, vector<vector<int>> &dp){
            int n= weight.size();
            if(idx == n || currWeight >= maxWeight)return 0;
            if(dp[idx][currWeight] != -1)return dp[idx][currWeight];

            int take = 0;
            if(weight[idx] + currWeight <=maxWeight) 
                take = value[idx] + memoized_find(idx+1, currWeight + weight[idx], weight, value, maxWeight, dp);
            int notTake = memoized_find(idx+1, currWeight, weight, value, maxWeight, dp);

            return dp[idx][currWeight] = max(take, notTake);
        }
public:
    int recursion(vector<int> weight, vector<int> value, int n, int maxWeight){
        return recursive_find(0, 0, weight, value, maxWeight);
    }

    int memoization(vector<int> weight, vector<int> value, int n, int maxWeight){
        vector<vector<int>> dp (n+1, vector<int> (maxWeight+1, -1));
        return memoized_find(0, 0, weight, value, maxWeight, dp);
    }

    int tabulation(vector<int> weight, vector<int> value, int n, int maxWeight){
        vector<vector<int>> dp (n+1, vector<int> (maxWeight+1, 0));
        for(int w = weight[0]; w <= maxWeight; w++) dp[0][w] = value[0];

        for(int item = 1; item<n; item++){
            for(int wt = 0; wt <= maxWeight; wt++){
                int take = INT_MIN;
                if(weight[item] <= wt) 
                    take = value[item] + dp[item-1][wt - weight[item]];
                int notTake = 0 + dp[item-1][wt];

                dp[item][wt] = max(take, notTake);
            }
        }

        return dp[n-1][maxWeight];
    }

    int spaceOpt(vector<int> weight, vector<int> value, int n, int maxWeight){
        vector<int> dp1(maxWeight+1, 0);
        vector<int> dp2 (maxWeight+1, 0);

        for(int w = weight[0]; w <= maxWeight; w++) dp1[w] = value[0];

        for(int item = 1; item<n; item++){
            for(int wt = 0; wt <= maxWeight; wt++){
                int take = INT_MIN;
                if(weight[item] <= wt) 
                    take = value[item] + dp1[wt - weight[item]];
                int notTake = 0 + dp1[wt];

                dp2[item] = max(take, notTake);
            }

            dp1 = dp2;
            dp2.assign(maxWeight+1, 0);
        }

        return dp1[maxWeight];
    }
};