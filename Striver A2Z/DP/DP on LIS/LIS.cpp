#include <bits/stdc++.h>
using namespace std;

class LIS{
private:
    int recursive_find(int idx, int last, const vector<int> &nums) {
        int n = nums.size();
        if (idx == n) return 0;

        int len = 0 + recursive_find(idx+1, last, nums);    
        if(last == -1 || nums[last] < nums[idx]){
            len = max(len, 1 + recursive_find(idx+1, idx, nums));
        }

        return len;
    }

    int memoized_find(int idx, int last, const vector<int> &nums, vector<vector<int>> &dp){
        int n = nums.size();
        if (idx == n) return 0;
        if(dp[idx][last+1] != -1)return dp[idx][last+1];

        int len = 0 + memoized_find(idx+1, last, nums, dp);    
        if(last == -1 || nums[last] < nums[idx]){
            len = max(len, 1 + memoized_find(idx+1, idx, nums, dp));
        }

        return dp[idx][last+1] = len;
    }
public:
    int recursion(vector<int> &nums){
        return recursive_find(0, -1, nums);
    }

    int memoization(vector<int> &nums){
        int n = nums.size();
        vector<vector<int>> dp  (n, vector<int> (n+1, -1));
        return memoized_find(0, -1, nums, dp);
    }

    int tabulation(vector<int> &nums){
        int n = nums.size();
        vector<vector<int>> dp  (n+1, vector<int> (n+1, 0));

        for(int idx = n-1; idx >= 0; idx--){
            for(int last = idx -1; last >= -1; last--){
                int len = 0 + dp[idx+1][last+1];
                if(last == -1 || nums[last] < nums[idx]){
                    len = max(len, 1 + dp[idx+1][idx+1]);
                }
                dp[idx][last+1] = len;
            }
        }

        return dp[0][0];
    }

    int spaceOpt(vector<int> &nums){
        int n = nums.size();
        vector<int> curr (n+1, 0), prev (n+1, 0);

        for(int idx = n-1; idx >= 0; idx--){
            for(int last = idx -1; last >= -1; last--){
                
                int len = 0 + prev[last+1];

                if(last == -1 || nums[last] < nums[idx]){
                    len = max(len, 1 + prev[idx+1]);
                }
                curr[last+1] = len;
            }

            prev = curr;
        }        

        return prev[0];
    }

    int algorithminApproach(vector<int> &nums){
        int n = nums.size(), ans = 0;
        vector<int> dp (n, 1);

        for(int curr=0; curr<n; curr++){
            for(int prev=0; prev<curr; prev++){
                if(nums[prev] < nums[curr] && dp[curr] < dp[prev] + 1){
                    dp[curr] = dp[prev] + 1;
                    ans = max(ans, dp[curr]);
                }
            }
        }

        return ans;
    }
};