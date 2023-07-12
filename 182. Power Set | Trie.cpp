//CodeStudio Code
#include <bits/stdc++.h> 

void powerSet(const vector<int>& v, vector<int> output, vector<vector<int>>& ans, int index) {
    if(index >= v.size()) {
        ans.push_back(output);
        return;
    }
    powerSet(v, output, ans, index+1);
    output.push_back(v[index]);
    powerSet(v, output, ans, index+1);
}

vector<vector<int>> pwset(const vector<int>& v) {
    vector<vector<int>> ans;
    vector<int> output;
    powerSet(v, output, ans, 0);
    return ans;
}
