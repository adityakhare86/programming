#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    int find(int n, vector<int> &dp){
        if(dp[n] != -1) return dp[n];
        return find(n-1, dp) + find(n-2, dp);
    }
public:
    int fibonnaci(int n){
        if(n == 0)return 0;
        if(n == 1)return 1;

        vector<int> dp (n+1, -1);
        dp[0] = 0; dp[1] = 1;
        return find(n, dp);
    }
};

int main(){
    int n = 3;

    Solution obj;
    int ans = obj.fibonnaci(n-1);
    cout<<ans<<'\n';
    return 0;
}