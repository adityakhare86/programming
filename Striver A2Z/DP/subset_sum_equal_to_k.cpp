#include <bits/stdc++.h>
using namespace std;

class SubsetSumK{
private:
    bool recursive_find(int idx, int sum, int k, const vector<int> &arr){
        int n = arr.size();
        if(sum == k)return true;
        if(idx >= n)return false;

        bool take = recursive_find(idx+1, sum + arr[idx], k, arr);
        bool notTake = recursive_find(idx+1, sum, k, arr);

        return take||notTake;
    }

    bool memoized_find(int idx, int sum, int k, vector<int> &dp, const vector<int> &arr){
        int n = arr.size();
        if(sum == k)return true;
        if(idx >= n)return false;
        if(dp[idx] != -1)return dp[idx];

        bool take = memoized_find(idx+1, sum + arr[idx], k, dp, arr);
        bool notTake = memoized_find(idx+1, sum, k, dp, arr);

        return dp[idx] = take||notTake;
    }
public:
    int recursion(int n, int k, vector<int> &arr){
        return recursive_find(0, 0, k, arr);
    }

    int memoization(int n, int k, vector<int> &arr){
        vector<int> dp (n, -1);
        return memoized_find(0, 0, k, dp, arr);
    }
};