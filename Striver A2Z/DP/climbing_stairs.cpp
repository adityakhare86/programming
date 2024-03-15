#include <bits/stdc++.h>
using namespace std;


//Time : O(2^n) 
//Space: O(2^n) for the recursion stack space
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

//Time : O(n) 
//Space: O(n) due to dp vector and recursion stack space
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

//Time: O(n)
//Space: O(n) due to dp vector
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

//Time : O(n)
//Space : O(1)
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