//CodeStudio Code
#include <bits/stdc++.h>

unordered_map<string, int> dp;
vector<string> ans;
    

void solve(string s, int idx, string ds) {
    if(idx == s.size()) {
        ans.emplace_back(ds);
        return;
    }
    string tmp = "";
    for(int i {idx}; i < s.length(); ++i) {
        tmp += s[i];
        if(dp[tmp]) solve(s, i+1, ds+tmp+" ");
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary) {
    ans.clear();
    dp.clear();
    for(const string& word:dictionary) dp[word]++;
    solve(s, 0, "");
    return ans;
}
