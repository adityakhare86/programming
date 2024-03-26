#include <bits/stdc++.h>
using namespace std;

class PartitionArray{
private:
    int recursive_find(int idx, int count, int sum, int totalSum, 
        const vector<int> &nums){
            int n = nums.size();
            if(idx == n){
                if(count != n/2)return 1e9;
                return abs((totalSum-sum) - sum);
            }

            int notTake = recursive_find(idx+1, count, sum, totalSum, nums);
            int take = recursive_find(idx+1, count+1, sum + nums[idx], totalSum, nums);

            return min(take, notTake);
    }

    int memoized_find(int idx, int count, int sum, int totalSum, 
        const vector<int> &nums, vector<unordered_map<int,int>> &dp){
            int n = nums.size();
            if(idx == n){
                if(count != n/2)return 1e9;
                return abs((totalSum-sum) - sum);
            }
            if(dp[idx].find(sum) != dp[idx].end())return dp[idx].at(sum);

            int notTake = memoized_find(idx+1, count, sum, totalSum, nums, dp);
            int take = memoized_find(idx+1, count+1, sum + nums[idx], totalSum, nums, dp);

            dp[idx].insert({sum , min(take, notTake)});
            return dp[idx].at(sum);
        }
public:
    int recursion(vector<int>& nums){
        int n = nums.size(), totalSum = 0;
        for(int i=0; i<n; i++)totalSum += nums[i];
        return recursive_find(0, 0, 0, totalSum, nums);
    }
    
    int memoization(vector<int> &nums){
        int n = nums.size(), totalSum = 0;
        for(int i=0; i<n; i++)totalSum += nums[i];
        vector<unordered_map<int, int>> dp (n);
        return memoized_find(0, 0, 0, totalSum, nums, dp);
    }
};