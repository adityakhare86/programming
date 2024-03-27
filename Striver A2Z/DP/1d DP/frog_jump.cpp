/*
Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. 
At a time the frog can climb either one or two steps. 
A height[N] array is also given. Whenever the frog jumps from a stair i to stair j, 
the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. 
We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1.
*/

#include <bits/stdc++.h>
using namespace std;

class recursion{
private:
    int find(int n, vector<int> &height){
        if(n == 0) return 0;

        int oneStep = find(n - 1, height) + abs(height[n] - height[n-1]);
        int twoStep = INT_MAX;
        if(n>1)twoStep = find(n-2, height) + abs(height[n] - height[n-1]);

        return min(oneStep, twoStep);
    }
public:
    int frogJump(int n, vector<int> height){
        return find(n, height);
    }
};

class memoization{
private:
    int find(int n, vector<int> &height, vector<int> &dp){
        if(n == 0) return 0;
        if(dp[n] != -1)return dp[n];

        int oneStep = find(n - 1, height, dp) + abs(height[n] - height[n-1]);
        int twoStep = INT_MAX;
        if(n>1)twoStep = find(n-2, height, dp) + abs(height[n] - height[n-1]);

        return dp[n] = min(oneStep, twoStep);
    }
public:
    int frogJump(int n, vector<int> height){
        vector<int> dp (n, -1);
        return find(n-1, height, dp);
    }
};

class tabulation{
public:
    int frogJump(int n, vector<int> height){
        vector<int> dp(n, -1);
        dp[0] = 0;

        for(int i=1; i<n; i++){
            int oneStep = dp[i-1] + abs(height[i] - height[i-1]);
            int twoStep = INT_MAX;
            if(i>1) twoStep = dp[i-2] + abs(height[i] - height[i-2]);

            dp[i] = min(oneStep, twoStep);
        }

        return dp[n-1];
    }
};

class spaceOptimized{
public:
    int frogJump(int n, vector<int> height){

        int ans = INT_MAX;
        int prev1 = 0, prev2 = 0;

        for(int i=1; i<n; i++){
            int oneStep = prev1 + abs(height[i] - height[i-1]);
            int twoStep = INT_MAX;
            if(i>1){
                twoStep = prev2 + abs(height[i] - height[i-2]);
            }

            int ans = min(oneStep, twoStep);
            prev2 = prev1;
            prev1 = ans;
        }

        return prev1;
    }
};