#include <bits/stdc++.h>
using namespace std;

class LCS{
private:
public:
    int tabulation(string &s1, string &s2){
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

            int ans = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (s1[i - 1] == s2[j - 1]) {
                        int temp = 1 + dp[i - 1][j - 1];
                        dp[i][j] = temp;
                        ans = max(ans, temp);
                    } else {
                        dp[i][j] = 0;
                    }
                }
            }

        return ans;
    }

    int spaceOpt(string &s1, string &s2){
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

            int ans = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (s1[i - 1] == s2[j - 1]) {
                        int temp = 1 + dp[i - 1][j - 1];
                        dp[i][j] = temp;
                        ans = max(ans, temp);
                    } else {
                        dp[i][j] = 0;
                    }
                }
            }

        return ans;
    }
};
