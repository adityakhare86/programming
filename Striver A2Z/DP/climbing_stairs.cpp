#include <bits/stdc++.h>
using namespace std;

class recursive{
private:
    int find(int n){
        if(n<=2) return n;
        return find(n-1) + find(n-2);
    }
public:
    int climbingStairs(int n){
        return find(n);
    }
};

class memoization{
private:
    int find(int n, vector<int> &dp){
        if(n<=2) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = dp[n-1] + dp[n-2];
    }
public:
    int climbingStairs(int n){
        vector<int> dp (n, -1);
        return find(n, dp);
    }
};

class tabulation{
public:
    int climbingStairs(int n){
        if(n<=2) return n;
        vector<int> dp(n+1, -1);
        dp[1] = 1, dp[2] = 2;

        for(int i=3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};

class spaceOptimized{
public:
    int climbingStairs(int n){
        if(n <= 2) return n;

        int ans, prev1 = 1, prev2 = 2;
        for(int i=3; i<=n; i++){
            ans = prev1 + prev2;
            prev1 = prev2;
            prev2 = ans;
        }

        return ans;
    }
};