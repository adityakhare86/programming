#include <bits/stdc++.h>
using namespace std;

class WildcardMatching{
private:
    bool recursive_find(int p, int q, string &text, string &pattern){
        int n = text.size(), m = pattern.size();
        if(p==n && q==m)return true;
        if(q==m || p==n)return false;

        if(text[p] == pattern[q]){
            return recursive_find(p+1, q+1, text, pattern);
        }
        else if(pattern[q] == '?'){
            return recursive_find(p+1, q+1, text, pattern);
        }
        else if(pattern[q] == '*'){
            bool take = recursive_find(p+1, q+1, text, pattern);
            bool notTake = recursive_find(p+1, q, text, pattern);
            bool ignore = recursive_find(p, q+1, text, pattern);
            return (take || notTake || ignore);
        }
        return false;
    }

    bool memoized_find(int p, int q, string &text, string &pattern,
        vector<vector<int>> &dp){
        int n = text.size(), m = pattern.size();
        if(p==n && pattern[q]=='*'){
            return dp[p][q] = memoized_find(p, q+1, text, pattern, dp);
        }
        if(p==n && q==m)return true;
        if(q==m || p==n)return false;
        if(dp[p][q] != -1)return dp[p][q];

        if(text[p] == pattern[q]){
            return dp[p][q] = memoized_find(p+1, q+1, text, pattern, dp);
        }
        else if(pattern[q] == '?'){
            return dp[p][q] = memoized_find(p+1, q+1, text, pattern, dp);
        }
        else if(pattern[q] == '*'){
            bool take = memoized_find(p+1, q+1, text, pattern, dp);
            bool notTake = memoized_find(p+1, q, text, pattern, dp);
            bool ignore = memoized_find(p, q+1, text, pattern, dp);
            return dp[p][q] = (take || notTake || ignore);
        }
        return dp[p][q] = false;
    }

    bool stars(string pattern, int i){
        for(int j=1; j<=i; j++){
            if(pattern[j-1] != '*')return false;
        }
        return true;
    }
public:
    bool recursion(string text, string pattern){
        return recursive_find(0, 0, text, pattern);
    }

    bool memoization(string text, string pattern){
        int p = text.size(), q = pattern.size();
        vector<vector<int>> dp (p+1, vector<int> (q+1, -1));
        return memoized_find(0, 0, text, pattern, dp);
    }

    int tabulation(string text, string pattern){
        int p = text.size(), q = pattern.size();
        vector<vector<bool>> dp (p+1, vector<bool> (q+1, 0));

        dp[0][0] = true;
        for(int i=1; i<=q; i++)dp[0][i] = stars(pattern, i);


        for(int i=1; i<=p; i++){
            for(int j=1; j<=q; j++){
                if(pattern[j-1] == text[i-1] || pattern[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(pattern[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else{
                    dp[i][j] = false;
                }
            }
        }

        return dp[p][q];
    }
};