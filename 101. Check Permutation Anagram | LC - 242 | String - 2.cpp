//CodeStudio Code
#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    vector<int> freq1(26, 0), freq2(26, 0);
    for(char i:str1) freq1[i-'a']++;
    for(char i:str2) freq2[i-'a']++;
    return freq1==freq2;
}

//LeetCode Code
class Solution {
public:
    bool isAnagram(string s, string t) {
        int sn = size(s), tn = size(t);
        if(sn != tn) return false;
        int ss[26] = {}, tt[26] = {};
        for(int i {}; i < sn; i++) ss[s[i]-'a']++;
        for(int i {}; i < sn; i++) tt[t[i]-'a']++;
        for(int i {}; i < 26; i++) if(ss[i] != tt[i]) return false;
        return true;
    }
};
