#include <bits/stdc++.h>
using namespace std;

class StocksFee{
private:
    int recursive_find(int idx, int fee, vector<int> &prices){
        int n = prices.size();
        if(idx >= n-1)return 0;

        if(prices[idx+1] > prices[idx] + fee)
            return prices[idx+1] - (prices[idx] + fee) + recursive_find(idx+1, fee, prices);
        
        return recursive_find(idx+1, fee, prices);
    }
public:
    int recursion(vector<int> &prices, int fee){
        return recursive_find(0, fee, prices);
    }
};