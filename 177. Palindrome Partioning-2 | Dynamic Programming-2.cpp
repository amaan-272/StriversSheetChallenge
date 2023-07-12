//CodeStudio Code
#include <bits/stdc++.h> 
int solve(string& s, int start, int end, vector<vector<int>>& dp, vector<vector<bool>>& isPal) {
    if(start >= end) return dp[start][end] = 0;
    if(isPal[start][end]) return dp[start][end] = 0;
    if(dp[start][end] != -1) return dp[start][end];
    int ans = 1e6;
    for(int i {start}; i < end; i++) {
        if(dp[start][i] == -1) dp[start][i] = solve(s, start, i, dp, isPal);
        if(dp[i+1][end] == -1) dp[i+1][end] = solve(s, i+1, end, dp, isPal);
        ans = min(ans, 1+dp[start][i]+dp[i+1][end]);
    }
    return dp[start][end] = ans;
}

int palindromePartitioning(string str) {
    int n = str.size();
    vector<vector<bool>> isPal(n, vector<bool>(n));
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for(int i {}; i < n; i++) {
        isPal[i][i] = true;
        if(i+1 < n) isPal[i][i+1] =(str[i] == str[i+1]);
    }
    for(int k {3}; k <= n; k++) for(int i = 0; i <= n-k; i++) isPal[i][i+k-1] = (isPal[i+1][i+k-2] && str[i] == str[i+k-1]);
    return solve(str, 0, n-1, dp, isPal);
}
