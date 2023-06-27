//CodeStudio Code
#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	vector<vector<int>>dp(m, vector<int>(n, 0));
	for(int i {}; i < m; i++) dp[i][0] = 1;
	for(int j {}; j < n; j++) dp[0][j] = 1;
	for(int i {}; i < m; i++) for(int j {}; j < n; j++) if(i && j) dp[i][j] = dp[i-1][j]+dp[i][j-1];
	return dp[m-1][n-1];
}

//LeetCode Code
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, 0));
	    for(int i {}; i < m; i++) dp[i][0] = 1;
	    for(int j {}; j < n; j++) dp[0][j] = 1;
	    for(int i {}; i < m; i++) for(int j {}; j < n; j++) if(i && j) dp[i][j] = dp[i-1][j]+dp[i][j-1];
	    return dp[m-1][n-1];
    }
};
