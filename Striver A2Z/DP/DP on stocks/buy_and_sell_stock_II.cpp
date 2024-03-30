#include <bits/stdc++.h>
using namespace std;

class StocksII{
private:
    int recursive_find(int idx, vector<int> &prices){
        int n = prices.size();
        if(idx == n-1 || idx == n)return 0;

        if(prices[idx+1] > prices[idx])return (prices[idx+1] - prices[idx]) + recursive_find(idx+1, prices);
        return recursive_find(idx+1, prices);
    }
public:
    int recursion(vector<int> &prices){
        return recursive_find(0, prices);
    }

    int tabulation(vector<int> &prices){
        int n = prices.size();
        vector<int> dp (n, 0);

        for(int i=1; i<n; i++){
            if(prices[i-1] < prices[i]) dp[i] = prices[i] - prices[i] + dp[i-1];
            else dp[i] = dp[i-1];
        }

        return dp[n-1];
    }

    int spaceOpt(vector<int> &prices){
        int n = prices.size();
        int ans = 0;

        for(int i=1; i<n; i++){
            if(prices[i-1] < prices[i])ans += (prices[i] - prices[i-1]);
        }

        return ans;
    }
};