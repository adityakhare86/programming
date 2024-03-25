#include <bits/stdc++.h>
using namespace std;

class TargetSum{
private:
    int recursive_find(int idx, int leftOver, const vector<int> &nums){
        int n = nums.size();
        if(idx == n){
            if(leftOver == 0)return 1;
            return 0;
        }

        int add = recursive_find(idx+1, leftOver + nums[idx], nums);
        int sub = recursive_find(idx+1, leftOver - nums[idx], nums);

        return add + sub;
    }

    int memoized_find(int idx, int leftOver, const vector<int> &nums, vector<vector<int>> &dp){
        int n = nums.size();
        if(idx == n-1){
            if(leftOver == 0 && nums[idx] == 0)return 2;
            if(leftOver == 0 || nums[idx] == leftOver)return 1;
            return 0;
        }
        if(dp[idx][leftOver] != -1)return dp[idx][leftOver];

        int taken = 0;
        int notTaken = memoized_find(idx+1, leftOver, nums, dp);
        if(nums[idx] <= leftOver)
            taken = memoized_find(idx+1, leftOver - nums[idx], nums, dp);

        return dp[idx][leftOver] = taken + notTaken;
    }
public:
    int recursion(vector<int>& nums, int target){
        return recursive_find(0, target, nums);
    }
    
    int memoization(vector<int>& nums, int target){
        int n = nums.size();
        int total = 0;
        for(int i=0; i<n; i++) total += nums[i];
        if(total - target < 0)return 0;
        if((total - target)%2 == 1)return 0;

        int newSum = (total-target)/2;

        vector<vector<int>> dp (n, vector<int> (newSum+1, -1));
        return memoized_find(0, newSum, nums, dp);
    }

    int tabulation(vector<int>& nums, int target){
        int n = nums.size(), total = 0;
        for(int i=0; i<n; i++)total += nums[i];
        if(total - target < 0)return 0;
        if((total - target)%2 == 1)return 0;

        int newSum = (total - target)/2;
        
        vector<vector<int>> dp (n, vector<int> (newSum+1, 0));
        if (nums[0] == 0)
            dp[0][0] = 2;  
        else
            dp[0][0] = 1;  // 1 case - not pick

        if (nums[0] != 0 && nums[0] <= newSum)
            dp[0][nums[0]] = 1;

        for(int idx = 1; idx<n; idx++){
            for(int sum = 0; sum<=newSum; sum++){
                int taken = 0;
                int notTaken = dp[idx-1][sum];
                if(nums[idx] <= sum)
                    taken = dp[idx-1][sum - nums[idx]];

                dp[idx][sum] = taken + notTaken;
            }
        }

        return dp[n-1][newSum];
    }

    int spaceOpt(vector<int>& nums, int target){
        int n = nums.size(), total = 0;
        for(int i=0; i<n; i++)total += nums[i];
        if(total - target < 0)return 0;
        if((total - target)%2 == 1)return 0;

        int newSum = (total - target)/2;
        
        vector<int> dp1 (newSum+1, 0), dp2 (newSum+1, 0);
        if (nums[0] == 0)
            dp1[0] = 2;  
        else
            dp1[0] = 1;  // 1 case - not pick

        if (nums[0] != 0 && nums[0] <= newSum)
            dp1[nums[0]] = 1;

        for(int idx = 1; idx<n; idx++){
            for(int sum = 0; sum<=newSum; sum++){
                int taken = 0;
                int notTaken = dp1[sum];
                if(nums[idx] <= sum)
                    taken = dp1[sum - nums[idx]];

                dp2[sum] = taken + notTaken;
            }

            dp1 = dp2;
            dp2.assign(newSum+1, 0);
        }

        return dp1[newSum];
    }
};