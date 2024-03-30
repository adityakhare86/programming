#include <bits/stdc++.h>
using namespace std;

class Stocks{
private:
    int recursive_find(int idx, const vector<int> &prices){
        int n = prices.size();
        if(idx == n-1)return 0;
        int buy = prices[idx], sell = 0;
        for(int i=idx+1; i<n; i++){
            sell = max(sell, prices[i]);
        }

        return max(sell - buy, recursive_find(idx+1, prices));
    }

public:
    int recursion(vector<int> &prices){
        if(prices.size() < 2)return 0;
        return recursive_find(0, prices);
    }

    int tabulation(vector<int> &prices){
        int n = prices.size();
        if(prices.size() < 2)return 0;
        
        vector<int> dp(n);
        dp[0] = prices[0];

        int ans = 0;
        for(int i=1; i<n; i++){
            ans = max(ans, prices[i] - dp[i-1]);
            dp[i] = min(prices[i], dp[i-1]);
        }

        return ans;
    }

    int spaceOpt(vector<int> &prices){
        int n = prices.size();
        if(prices.size() < 2)return 0;

        int mini = prices[0];
        int ans = 0;

        for(int i=1; i<n; i++){
            ans = max(ans, prices[i] - mini);
            mini = min(mini, prices[i]);
        }

        return ans;
    }
};