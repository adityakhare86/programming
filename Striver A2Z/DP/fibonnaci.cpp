/*
Time (memoized): O(n)
Space: O(n) due recursion stack space and dp array 
*/


#include <bits/stdc++.h>
using namespace std;

class Memoized_fib{
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

int main(){
    int n = 7;

    Memoized_fib obj;
    int ans = obj.fibonnaci(n);
    cout<<ans<<'\n';
    return 0;
}