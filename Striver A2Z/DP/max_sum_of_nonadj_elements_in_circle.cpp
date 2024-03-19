#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0], nums[1]);
        vector<int> dp1 (n-1, -1), dp2 (n, -1);

        dp1[0] = nums[0];
        for(int i=1; i<n-1; i++){
            int take = nums[i];
            if(i>1)take += dp1[i-2];
            int notTake = dp1[i-1];

            dp1[i] = max(take, notTake);
        }

        dp2[0] = 0, dp2[1] = nums[1];
        for(int i=2; i<n; i++){
            int take = nums[i] + dp2[i-2];
            int notTake = dp2[i-1];

            dp2[i] = max(take, notTake);
        }

        return max(dp1[n-2], dp2[n-1]);
    }
};