/*
Time (memoized): O(n)
Space: O(n) due recursion stack space and dp array 
*/


#include <bits/stdc++.h>
using namespace std;

class memoizedFib{
private:
    int find(int n, vector<int> &dp){
        if(n <= 1) return n;
        if(dp[n] != -1) return dp[n]; 
        return dp[n] = find(n-1, dp) + find(n-2, dp); //memoization
    }
public:
    int fibonnaci(int n){
        vector<int> dp (n+1, -1);
        return find(n, dp);
    }
};

class tabulatedFib{
public:
    int fibonacci(int n){
        vector<int> dp(n+1);
        dp[0] = 0, dp[1] = 1;
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

class spaceOptFib{
public:
    int fibonacci(int n){
        if(n<=1) return n;
        int prev1 = 0, prev2 = 1;
        int ans;
        for(int i=2; i<=n; i++){
            ans = prev1 + prev2;
            prev1 = prev2;
            prev2 = ans;
        }
        return ans;
    }
};

int main(){
    int n = 7;

    tabulatedFib obj;
    int ans = obj.fibonacci(n);
    cout<<ans<<'\n';
    return 0;
}