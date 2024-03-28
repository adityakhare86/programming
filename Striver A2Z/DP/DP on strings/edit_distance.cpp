#include <bits/stdc++.h>
using namespace std;

class DistinctSubs{
private:
    int recursive_find(int p, int q, string &s1, string &s2){
        if(p == -1)return q+1;
        if(q == -1)return p+1;

        if(s1[p] == s2[q])return 0 + recursive_find(p-1, q-1, s1, s2);
        
        int del = 1 + recursive_find(p-1, q, s1, s2);
        int rep = 1 + recursive_find(p-1, q-1, s1, s2);
        int ins = 1 + recursive_find(p, q-1, s1, s2);

        return min({del, rep, ins});
    }

    int memoized_find(int p, int q, string &s1, string &s2, vector<vector<int>> &dp){
        if(p == -1)return q+1;
        if(q == -1)return p+1;
        if(dp[p][q] != -1)return dp[p][q];

        if(s1[p] == s2[q])return 0 + memoized_find(p-1, q-1, s1, s2, dp);
        
        int del = 1 + memoized_find(p-1, q, s1, s2, dp);
        int rep = 1 + memoized_find(p-1, q-1, s1, s2, dp);
        int ins = 1 + memoized_find(p, q-1, s1, s2, dp);

        return dp[p][q] = min({del, rep, ins});
    }
public:
    int recursion(string s1, string s2){
        int n = s1.size(), m = s2.size();
        return recursive_find(n-1, m-1, s1, s2);
    }

    int memoization(string s1, string s2){
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp (n, vector<int> (m, -1));
        return memoized_find(n-1, m-1, s1, s2, dp);
    }

    int tabulation(string s1, string s2){
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp (n+1, vector<int> (m+1, 0));

        for(int i=0; i<=n; i++)dp[i][0] = i;
        for(int i=0; i<=m; i++)dp[0][i] = i;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    int del = dp[i-1][j];
                    int rep = dp[i-1][j-1];
                    int ins = dp[i][j-1];
                    dp[i][j] = 1 + min({del, rep, ins});
                }
            }
        }

        return dp[n][m];
    }

    int spaceOpt(string s1, string s2){
        int n = s1.size(), m = s2.size();
        vector<int> dp1 (m+1, 0), dp2 (m+1, 0);

        for(int i=0; i<=m; i++)dp1[i] = i;

        for(int i=1; i<=n; i++){
            dp2[0] = i;
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1]){
                    dp2[j] = dp1[j-1];
                }
                else{
                    int del = dp1[j];
                    int rep = dp1[j-1];
                    int ins = dp2[j-1];
                    dp2[j] = 1 + min({del, rep, ins});
                }
            }
            dp1 = dp2;
            dp2.assign(m+1, 0);
        }

        return dp1[m];
    }
};