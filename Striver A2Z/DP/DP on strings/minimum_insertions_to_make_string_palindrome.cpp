#include <bits/stdc++.h>
using namespace std;

class MakePalindrome{
public:
    int tabulation(string s){
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }

    int spaceOpt(string s){
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;
        int n = s1.size(), m = s2.size();
        vector<int> dp1(m+1, 0), dp2(m+1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp2[j] = 1 + dp1[j - 1];
                } else {
                    dp2[j] = max(dp1[j], dp2[j - 1]);
                }
            }
            dp1 = dp2;
            dp2.assign(m+1, 0);
        }

        return dp1[m];
    }
};