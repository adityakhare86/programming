#include <bits/stdc++.h>
using namespace std;

class PartitionEqualSubset{
private:
    bool recursive_find(int idx, int sum, int k, const vector<int> &arr){
        int n = arr.size();
        if(sum == k)return true;
        if(idx >= n)return false;

        bool take = recursive_find(idx+1, sum + arr[idx], k, arr);
        bool notTake = recursive_find(idx+1, sum, k, arr);

        return take||notTake;
    }

    bool memoized_find(int idx, int sum, int k, vector<vector<int>> &dp, const vector<int> &arr){
        int n = arr.size();
        if(sum == k)return true;
        if(idx >= n || sum>k)return false;
        if(dp[idx][sum] != -1)return dp[idx][sum];

        bool take = false;
        if(arr[idx] + sum <= k) take = memoized_find(idx+1, sum + arr[idx], k, dp, arr);
        bool notTake = memoized_find(idx+1, sum, k, dp, arr);

        return dp[idx][sum] = take||notTake;
    }
public:
    bool recursion(int n, int k, vector<int> &arr){
        return recursive_find(0, 0, k, arr);
    }

    bool memoization(int n, int k, vector<int> &arr){
        vector<vector<int>> dp (n, vector<int> (k+1, -1));
        return memoized_find(0, 0, k, dp, arr);
    }

    bool tabulation(int n, int k, vector<int> &arr){
        //dp array marks if we can consider the element for our subset
        vector<vector<bool>> dp (n, vector<bool> (k+1, false));

        
        //target 0 can be achieved by taking none of the elements
        for(int i=0; i<n; i++){
            dp[i][0] = true;
        }

        if(arr[0] <= k){
            dp[0][arr[0]] = true;
        }

        for(int idx=1; idx<n; idx++){
            for(int target=1; target<k+1; target++){
                bool notTaken = dp[idx-1][target];
                bool taken = false;
                if(arr[idx] <= target){
                    taken = dp[idx-1][target-arr[idx]];
                }

                dp[idx][target] = notTaken || taken;
            }
        }

        return dp[n-1][k];
    }

    bool spaceOpt(int n, int k, vector<int> &arr){
        vector<bool> dp1 (k+1, false), dp2 (k+1, false);
        dp1[0] = true, dp2[0] = true;
        if(arr[0] <= k)
            dp1[arr[0]] = true;

        for(int idx = 1; idx<n; idx++){
            for(int target = 1; target<k+1; target++){
                bool notTaken = dp1[target];
                bool taken = false;
                if(arr[idx] <= target){
                    taken = dp1[target - arr[idx]];
                }

                dp2[target] = taken || notTaken;
            }
            dp1 = dp2;
            dp2.assign(k+1, false);
            dp2[0] = true;
        }

        return dp1[k];
    }
};