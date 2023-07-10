//CodeStudio Code
vector<int> dp;

int cut(vector<int> & arr, int n) {
    if(!n) return 0;
    if(dp[n] == -1) { 
        int ans {};
        for(int j {1}; j <= n; j++) ans = max(ans, arr[j-1]+cut(arr, n-j));
        dp[n] = ans;
        return ans;
    }
    return dp[n];
}
int cutRod(vector<int> &price, int n) {
  	dp.clear();
    dp.resize(n+1, -1);
    return cut(price, n);
}

//LeetCode Code
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.emplace_back(0); 
        cuts.emplace_back(n);
        sort(begin(cuts), end(cuts));
        int len = size(cuts);
        vector<vector<int>> dp(len, vector<int>(len, INT_MAX));
        for(int i {}; i < len; i++) dp[i][i] = 0;
        for(int i {}; i < len-1; i++) dp[i][i+1] = 0;
        for(int i {2}; i < len; i++) for(int j {}; j < len-i; j++) for(int k {j+1}; k <i+j; k++) dp[j][i+j] = min(dp[j][i+j], dp[j][k]+dp[k][i+j]+(cuts[i+j]-cuts[j]));
         return dp[0][len-1];   
    }
};
