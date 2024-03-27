#include <bits/stdc++.h>
using namespace std;

class UnboundedKnapSack{
private:
    int recursive_find(int idx, int capacity, const vector<int> &profit,
        const vector<int> &weight){
            int n = profit.size();
            if(idx == n-1){
                return (capacity/weight[n-1]) * profit[n-1];
            }

            int notTake = 0 + recursive_find(idx+1, capacity, profit, weight);
            int take = INT_MIN;
            if(weight[idx] <= capacity)
                take = profit[idx] + recursive_find(idx, capacity - weight[idx], profit, weight);

            return take;
    }  

    int memoized_find(int idx, int capacity, const vector<int> &profit,
        const vector<int> &weight, vector<vector<int>> &dp){
            int n = profit.size();
            if(idx == n-1){
                return (capacity/weight[n-1]) * profit[n-1];
            }
            if(dp[idx][capacity] != -1)return dp[idx][capacity];

            int take = INT_MIN;
            int notTake = 0 + memoized_find(idx+1, capacity, profit, weight, dp);
            if(weight[idx] <= capacity)
                take = profit[idx] + memoized_find(idx, capacity - weight[idx], profit, weight, dp);

            return dp[idx][capacity] = max(take, notTake);
        }
public:
    int recursion(int n, int w, vector<int> &profit, vector<int> &weight){
        return recursive_find(0, w, profit, weight);
    }

    int memoization(int n, int w, vector<int> &profit, vector<int> &weight){
        vector<vector<int>> dp (n, vector<int> (w+1, -1));
        return memoized_find(0, w, profit, weight, dp);
    }

    int tabulation(int n, int w, vector<int> &profit, vector<int> &weight){
        vector<vector<int>> dp (n, vector<int> (w+1, 0));
        for(int wt=0; wt<=w; wt++)dp[0][wt] = (wt/weight[0]) * profit[0];

        for(int idx=1; idx<n; idx++){
            for(int wt=0; wt<=w; wt++){
                int take = INT_MIN;
                int notTake = 0 + dp[idx-1][wt];
                if(weight[idx] <= wt)
                    take = profit[idx] + dp[idx][wt - weight[idx]];

                dp[idx][wt] = max(take, notTake);
            }
        }

        return dp[n-1][w];
    }

    int spaceOpt(int n, int w, vector<int> &profit, vector<int> &weight){
        vector<int> dp1 (w+1, 0), dp2 (w+1, 0);
        for(int wt=0; wt<=w; wt++)dp1[wt] = (wt/weight[0]) * profit[0];

        for(int idx=1; idx<n; idx++){
            for(int wt=0; wt<=w; wt++){
                int take = INT_MIN;
                int notTake = 0 + dp1[wt];
                if(weight[idx] <= wt)
                    take = profit[idx] + dp2[wt - weight[idx]];

                dp2[wt] = max(take, notTake);
            }
            dp1 = dp2;
            dp2.assign(w+1, 0);
        }

        return dp1[w];
    }
};
