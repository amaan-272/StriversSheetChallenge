//CodeStudio Code
#include <bits/stdc++.h>

string completeString(int n, vector<string>& a) {
    unordered_map<string, bool> nodes;
    string ans;
    for(string& i:a) nodes[i] = true;
    for(string& i:a) {
        string tmp;
        bool matching = true;
        for(char c:i) {
            tmp += c;   
            if(nodes.find(tmp) == end(nodes)) {
                matching = false;
                break;
            }
        }
        if(matching) if(ans.empty() || ans.size()<i.size() ||(ans.size()==i.size() && ans>i)) ans = i;
    }
    return ans.empty()? "None":ans;
}
