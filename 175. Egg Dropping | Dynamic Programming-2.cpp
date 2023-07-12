//CodeStudio Code
#include<bits/stdc++.h>

int eggbreak(int n, int k, vector<vector<int>>& dp) {
    if(!n || !k) return 0;
    if(k == 1) return n;
    if(n == 1) return 1;
    if(dp[n][k] != -1) return dp[n][k];
    int ans = INT_MAX, low{1}, high{n};
    while(low <= high) {
        int mid {low+(high-low)/2}, broken = eggbreak(mid-1, k-1, dp), ok = eggbreak(n-mid, k, dp), result = max(ok, broken);
        ans = min(result+1, ans);
        (broken < ok)? low=mid+1:high=mid-1;
    }
    return dp[n][k] = ans;
}

int cutLogs(int k, int n) {
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    return eggbreak(n, k, dp);
}
