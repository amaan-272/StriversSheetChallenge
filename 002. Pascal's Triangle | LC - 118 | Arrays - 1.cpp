//CodeStudio Code
#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) {
    vector<vector<long long int>> ans(n);
	ans[0].emplace_back(1);
    for(int i {1}; i < n; i++) {
        for(int j {}; j < i+1; j++) {
        long long int val {1};
        if(j && j<i) val = ans[i-1][j-1]+ans[i-1][j];
        ans[i].emplace_back(val);
        }
    }
    return ans;
}

//LeetCode Code
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i {}; i < numRows; i++) {
            ans[i].resize(i+1, 1);            
            for(int j {1}; j < i; j++) ans[i][j] = ans[i-1][j-1]+ans[i-1][j];  
        }
        return ans;
    }
};
