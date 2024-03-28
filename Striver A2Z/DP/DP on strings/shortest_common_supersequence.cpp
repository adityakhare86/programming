#include <bits/stdc++.h>
using namespace std;

class SuperSequence{
public:
    string tabulation(string s1, string s2){
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp (n+1, vector<int> (m+1, 0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        int i=n, j=m;
        string ans;
        while(i>0 && j>0){
            if(s1[i-1] == s2[j-1]){
                ans.push_back(s1[i-1]);
                i--; j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }

        reverse(ans.begin(), ans.end());
        int p = 0, q=0, r=0;
        string res;
        
        while(p<ans.size()){
            if(ans[p] == s1[q] && ans[p] == s2[r]){
                res.push_back(ans[p]);
                p++; q++; r++;
            }
            else if(ans[p] != s1[q] && ans[p] != s2[r]){
                res.push_back(s1[q]);
                res.push_back(s2[r]);
                q++; r++;
            }
            else if(ans[p] == s1[q]){
                res.push_back(s2[r]);
                r++;
            }
            else if(ans[p] == s2[r]){
                res.push_back(s1[q]);
                q++;
            }
        }

        while(q<s1.size()){
            res.push_back(s1[q]);
            q++;
        }

        while(r<s2.size()){
            res.push_back(s2[r]);
            r++;
        }

        return res;
    }
};