#include <bits/stdc++.h>
using namespace std;

class SubsetWithSumK{
private:
    int recursive_find(int idx, int sum, int k, const vector<int> &arr){
        int n = arr.size();
        if(sum == k)return 1;
        if(idx >= n)return 0;

        int notTake = recursive_find(idx+1, sum, k, arr);
        int take = recursive_find(idx+1, sum + arr[idx], k, arr);

        return notTake + take;
    }

    int memoized_find(int idx, int sum, int k, vector<vector<int>> &dp, const vector<int> &arr){
        int n = arr.size();
        if(sum == k)return 1;
        if(idx >= n)return 0;
        if(dp[idx][sum] != -1)return dp[idx][sum];

        int notTake = memoized_find(idx+1, sum, k, dp, arr);
        int take = memoized_find(idx+1, sum + arr[idx], k, dp, arr);

        return dp[idx][sum] = take + notTake;
    }
public:
    int recursion(int k, vector<int> &arr){
        return recursive_find(0, 0, k, arr);
    }
    int memoizatoin(int k, vector<int> &arr){
        int n = arr.size();
        vector<vector<int>> dp (n, vector<int> (k+1, -1));
        return memoized_find(0, 0, k, dp, arr);
    }
    int tabulation(int k, vector<int> arr){
        int n = arr.size();
        vector<vector<int>> dp (n, vector<int> (k+1, 0));

        for(int i=0; i<n; i++)dp[i][0] = 1;
        if(arr[0] <= k)dp[0][arr[0]] = 1;


        for(int idx=1; idx<n; idx++){
            for(int sum = 1; sum<= k; sum++){
                int notTake = dp[idx-1][sum];
                int take = 0;
                if(arr[idx] <= sum)take = dp[idx-1][sum - arr[idx]];

                dp[idx][sum] = take + notTake;
            }
        }

        return dp[n-1][k];
    }

    int spaceOpt(int k, vector<int> arr){
        int n = arr.size();
        vector<int> dp1 (k+1, 0), dp2(k+1, 0);
        
        dp1[0] = 1, dp2[0] = 1; 
        if(arr[0] <= k)dp1[arr[0]] = 1;

        for(int idx=1; idx<n; idx++){
            for(int sum = 1; sum<= k; sum++){
                int notTake = dp1[sum];
                int take = 0;
                if(arr[idx] <= sum)take = dp1[sum - arr[idx]];

                dp2[sum] = take + notTake;
            }

            dp1 = dp2;
            dp2.assign(k+1, 0);
            dp2[0] = 1;
        }

        return dp1[k];
    }
};