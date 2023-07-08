//CodeStudio Code
#include <bits/stdc++.h> 

vector<vector<string>> ans;
vector<string> store;

void dfs(string s, vector<vector<bool>>& dp, int ind) {
    if(ind >= s.size()) ans.push_back(store);
    for(int i {ind}; i < s.size(); i++) {
        if(s[ind]==s[i] && ((i-ind)<=2 || dp[ind+1][i-1])) {
            dp[ind][i] = true;
            store.emplace_back(s.substr(ind, i-ind+1));
            dfs(s, dp, i+1);
            store.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    dfs(s, dp, 0);
    return ans;
}

//LeetCode Code
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    vector<vector<string>> ans;
    vector<string> store;
        
    
    void dfs(string& s, int start, vector<vector<bool>>& dp) {
        if(start >= size(s)) ans.push_back(store);
        for(int end {start}; end < size(s); end++) {
            if(s[start]==s[end] && ((end-start)<=2 || dp[start+1][end-1])) {
                dp[start][end] = true;
                store.emplace_back(s.substr(start, end-start+1));
                dfs(s, end+1, dp);
                store.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        int n = size(s);
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        dfs(s, 0, dp);
        return ans;
    }
};
