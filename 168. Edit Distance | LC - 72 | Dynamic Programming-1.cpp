//CodeStudio Code
int editDistance(string str1, string str2) {
    int n1 = str1.size(), n2 = str2.size();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1));
    for(int i {}; i <= n1; i++) dp[i][0] = i;
    for(int i {}; i <= n2; i++) dp[0][i] = i;
    for(int i {1}; i < n1+1; i++) for(int j {1}; j < n2+1; j++) dp[i][j] = (str1[i-1]==str2[j-1])? dp[i-1][j-1]:(1+min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])));
    return dp[n1][n2];
}

//LeetCode Code
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = size(word1), len2 = size(word2);
        vector<vector<int>> dp(len1+1, vector<int>(len2+1));
        int rows {len1+1}, cols {len2+1};
        for(int i {}; i < rows; i++) dp[i][0] = i;
        for(int i {}; i < cols; i++) dp[0][i] = i;
        for(int i {1}; i < len1+1; i++) for(int j {1}; j < len2+1; j++) dp[i][j] = (word1[i-1] == word2[j-1])? dp[i-1][j-1]:(1+min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])));
        return dp[len1][len2];
    }
};
