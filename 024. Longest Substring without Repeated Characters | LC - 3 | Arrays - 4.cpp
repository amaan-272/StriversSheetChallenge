//CodeStudio Code
#include <bits/stdc++.h> 
int uniqueSubstrings(string input) {
    vector<int> freq(26, -1);
    int ans {}, start {-1};
    for(int i = 0; i < input.size(); i++) {
        start = max(freq[input[i]]-'a', start);
        freq[input[i]-'a'] = i;
        ans = max(ans, i-start);
    }
    return ans;
}

//LeetCode Code
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> store(256, -1);
        int ans = 0, start = -1;
        for(int i = 0; i != s.length(); i++) {
            if(store[s[i]] > start) start = store[s[i]];
            store[s[i]] = i;
            ans = max(ans, i-start);
        }
        return ans;
    }
};
