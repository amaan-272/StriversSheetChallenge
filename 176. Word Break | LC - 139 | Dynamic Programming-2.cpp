//CodeStudio Code
bool wordBreak(vector<string>& arr, int n, string& target) {
    int i {};
    while(i < n) {
        if(target.find(arr[i]) != target.npos) target.erase(target.find(arr[i]), arr[i].size());
        else i++;
    }
    return target.size()? 0:1;
}

//LeetCode Code
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(size(s)+1, false);
        dp[0] = true;
        for(int i {1}; i <= size(s); i++) {
            for(int j {}; j < i; j++) {
                if(dp[j] && (find(begin(wordDict), end(wordDict), s.substr(j, i-j)) != end(wordDict))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};
