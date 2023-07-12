//CodeStudio Code
#include <bits/stdc++.h> 
int distinctSubstring(string& word) {
    unordered_set<string> ans;
    int n = word.size();
    for(int i {}; i < n; i++) {
        string subs = "";
        for(int j {i}; j < n; j++) {
            subs += word[j];
            ans.insert(subs);
        }
    }
    return ans.size();
}
