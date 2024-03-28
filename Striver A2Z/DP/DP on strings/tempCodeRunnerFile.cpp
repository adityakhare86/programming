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

        int ans = 0;
        int i=n,j=m;
        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                int count = 0;
                while(s1[i - 1] == s2[j - 1]){
                    count ++; 
                    i--; j--;
                }
                ans = max(ans, count);
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }

        for(auto row:dp){
            for(auto it:row)cout<<it<<' ';
            cout<<'\n';
        }
        cout<<ans;
        return ans;