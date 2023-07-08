//CodeStudio Code
vector<int> subsetSum(vector<int> &num) {
    int n = num.size(), sum = accumulate(begin(num), end(num), 0);
    vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
    vector<int> ans;
    dp[0][0] = 1;
    for(int i {1}; i <= n; i++) {
        int curr {num[i-1]};
        for(int j {}; j <= sum; j++) {
            int req {j-curr};
            if(req >= 0) dp[i][j] += dp[i-1][req];
            dp[i][j] += dp[i-1][j];
        }
    }
    for(int i {}; i <= sum; i++) for(int j {}; j < dp[n][i]; j++) ans.push_back(i);
    return ans;
}
