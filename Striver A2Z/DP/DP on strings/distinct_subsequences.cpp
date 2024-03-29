#include <bits/stdc++.h>
using namespace std;

class DistinctSubs{
private:
    int recursive_find(int p, int q, string &s1, string &s2){
        int n = s1.size(), m = s2.size();
        if(q == m){
            return 1;
        }
        if(p==n)return 0;

        if(s1[p] == s2[q]){
            int take = recursive_find(p+1, q+1, s1, s2);
            int notTake = recursive_find(p+1, q, s1, s2);
            return (take + notTake);
        }

        return recursive_find(p+1, q, s1, s2);
    }

    int memoized_find(int p, int q, string &s1, string &s2,
        vector<vector<int>> &dp){
        int n = s1.size(), m = s2.size();
        if(q == m){
            return 1;
        }
        if(p==n)return 0;
        if(dp[p][q] != -1)return dp[p][q];

        if(s1[p] == s2[q]){
            int take = memoized_find(p+1, q+1, s1, s2, dp);
            int notTake = memoized_find(p+1, q, s1, s2, dp);
            return dp[p][q] = (take + notTake);
        }

        return dp[p][q] = memoized_find(p+1, q, s1, s2, dp);
    }
public:
    int recursion(string s1, string s2){
        int n = s1.size(), m = s2.size();
        return recursive_find(0, 0, s1, s2);
    }

    int memoization(string s1, string s2){
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp (n, vector<int> (m, -1));
        return memoized_find(0, 0, s1, s2, dp);
    }

    int tabulation(string s1, string s2){
        int n = s1.size(), m = s2.size();
        vector<vector<unsigned int>> dp (n+1, vector<unsigned int> (m+1, -1));

        for(int i=0; i<=n; i++)dp[i][0] = 1;
        for(int i=1; i<=m; i++)dp[0][i] = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][m];
    }

};