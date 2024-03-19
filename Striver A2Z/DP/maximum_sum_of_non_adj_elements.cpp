#include <bits/stdc++.h>
using namespace std;

class frojJumpKdist{
private:
    int find(int idx, int k, vector<int> &heights){
        if(idx = 0)return 0;

        int ans = -1;
        for(int i=idx-1; i>= max(0, idx-k); i--){
            ans = max(ans, abs(heights[idx] - heights[i] + find(i, k, heights)));
        }
        
        return ans;
    }

    int memoized_find(int idx, int k, vector<int> &dp, vector<int> &heights){
        if(idx == 0)return 0;
        if(dp[idx] != -1)return dp[idx];

        int ans = -1;
        for(int i=idx-1; i>= max(0, idx-k); i--){
            ans = max(ans, abs(heights[idx] - heights[i] + find(i, k, heights)));
        }

        return dp[idx] = ans;
    }

public:
    int recursion(int k, vector<int> heights){
        int n = heights.size();
        return find(n-1, k, heights);
    }

    int memoization(int k, vector<int> heights){
        int n = heights.size();
        vector<int> dp (n, -1);
        return memoized_find(n-1, k, dp, heights);
    }

    int tabulation(int k, vector<int> heights){
        int n = heights.size();
        vector<int> dp (n, -1);
        dp[0] = 0;

        for(int i=0; i<n; i++){
            int take = heights[i];
            if(i>1) take += dp[i-2];
            int notTake = dp[i-1];
            dp[i] = max(take, notTake);
        }

        return dp[n-1];
    }

    int spaceOpt(int k, vector<int> heights){
        int n = heights.size();
        int prev1 = heights[0], prev2 = 0;

        for(int i=1; i<n; i++){
            int curr = max(prev1, heights[i] + prev2);
            
            prev2 = prev1;
            prev1 = curr;
        }
    }
};