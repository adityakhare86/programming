#include <bits/stdc++.h>
using namespace std;

class CutRod{
private:
    int recursive_find(int idx, int length, const vector<int> &price){
        int n = price.size();
        if(idx == n)
            return (length/idx) * price[idx-1];
        
        int notTake = 0 + recursive_find(idx+1, length, price);
		int take = INT_MIN;
        if(idx <= length)take = price[idx-1] + recursive_find(idx, length-idx, price);

        return max(take, notTake);
    }

    int memoized_find(int idx, int length, const vector<int> &price, vector<vector<int>> &dp){
        int n = price.size();
        if(idx == n)return (length/idx) * price[idx-1];
        if(dp[idx][length] != -1)return dp[idx][length];

        int notTake = 0 + memoized_find(idx+1, length, price, dp);
		int take = INT_MIN;
        if(idx <= length)take = price[idx-1] + memoized_find(idx, length-idx, price, dp);

        return dp[idx][length] = max(take, notTake);
    }
public:
    int recursion(vector<int> &price, int n){
        return recursive_find(1, n, price);
    }

    int memoization(vector<int> &price, int n){
        vector<vector<int>> dp (n, vector<int> (n+1, -1));
        return memoized_find(1, n, price, dp);
    }

    int tabulation(vector<int> &price, int n){
        vector<vector<int>> dp (n, vector<int> (n+1, 0));

        for(int i=0; i<=n; i++)dp[0][i] = i * price[0];

        for(int idx=1; idx<n; idx++){
            for(int length = 0; length<=n; length++){
                int notTake = 0 + dp[idx-1][length];
                int take = INT_MIN;
                if(idx <= length)take = price[idx-1] + dp[idx][length-idx];

                dp[idx][length] = max(take, notTake);
            }
        }

        return dp[n-1][n];
    }

    int spaceOpt(vector<int> &price, int n){
        vector<int> dp (n+1, 0);

        for(int i=0; i<=n; i++)dp[i] = i * price[0];

        for(int idx=1; idx<n; idx++){
            for(int length = 0; length<=n; length++){
                int notTake = 0 + dp[length];
                int take = INT_MIN;
                if(idx <= length)take = price[idx-1] + dp[length-idx];

                dp[length] = max(take, notTake);
            }
        }

        return dp[n];
    }
};