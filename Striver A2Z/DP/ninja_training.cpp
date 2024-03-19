#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    int find(int day, int last, vector<vector<int>> &points){
        int n = points.size();
        int maxi = 0;
        if(n==0){
            for(int i=0; i<3; i++){
                if(i != last)maxi = max(maxi, points[day][i]);
            }
            return maxi;
        }

        for(int i=0; i<3; i++){
            if(i != last){
                maxi = max(maxi, points[day][i] + find(day-1, i, points));
            }
        }

        return maxi;
    }

    int memoized_find(int day, int last, vector<vector<int>> &dp, vector<vector<int>> &points){
        if(dp[day][last] != -1)return dp[day][last];
        int n = points.size();

        int maxi = 0;
        if(n==0){
            for(int i=0; i<3; i++){
                if(i != last)maxi = max(maxi, points[day][i]);
            }
            return maxi;
        }

        for(int i=0; i<3; i++){
            if(i != last){
                maxi = max(maxi, points[day][i] + memoized_find(day-1, i, dp, points));
            }
        }

        return dp[day][last] = maxi;
    }
public:
    int recursion(int n, vector<vector<int>> &points){
        find(n-1, 3, points);
    }

    int memoization(int n, vector<vector<int>> &points){
        vector<vector<int>> dp(n, vector<int> (3, -1));
        memoized_find(n-1, 3, dp, points);
    }

    int tabulation(int n, vector<vector<int>> &points){
        vector<vector<int>> dp(n, vector<int> (3, 0));
        dp[0] = points[0];

        for(int i=1; i<n; i++){
            dp[i][0] = max(dp[i-1][0], points[i][0] + max(dp[i-1][1], dp[i-1][2]));
            dp[i][1] = max(dp[i-1][1], points[i][1] + max(dp[i-1][0], dp[i-1][2]));
            dp[i][2] = max(dp[i-1][2], points[i][2] + max(dp[i-1][0], dp[i-1][1]));
        }

        return max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
    }
};