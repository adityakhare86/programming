#include <bits/stdc++.h>
using namespace std;

class LCS{
private:
    int recursive_find(int i1, int i2, const string &s1, const string &s2){
        int n = s1.size(), m = s2.size();
        if(i1 >= n || i2 >= m)return 0;
        if(s1[i1] == s2[i2])return 1 + recursive_find(i1+1, i2+1, s1, s2);

        return max(recursive_find(i1+1, i2, s1, s2), recursive_find(i1, i2+1, s1, s2));
    }

    int memoized_find(int i1, int i2, const string &s1, const string &s2){
        int n = s1.size(), m = s2.size();
        if(i1 >= n || i2 >= m)return 0;
        if(dp[i1][i2] != -1)return dp[i1][i2];
        if(s1[i1] == s2[i2])return dp[i1][i2] = 1 + memoized_find(i1+1, i2+1, s1, s2, dp);

        return dp[i1][i2] = max(memoized_find(i1+1, i2, s1, s2, dp), memoized_find(i1, i2+1, s1, s2, dp));
    }
public:
    int recursion(string s1, string s2){
        return recursive_find(0, 0, s1, s2);
    }

    int memoization(string s1, string s2){
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp (n, vector<int> (m, -1));
        return memoized_find(0, 0, s1, s2, dp);
    }
}