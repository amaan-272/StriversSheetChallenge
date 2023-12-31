// CodeStudio Code 
#include <bits/stdc++.h> 
#define size(a) a.size()

void setZeros(vector<vector<int>> &matrix) {
	int n = size(matrix), m = size(matrix[0]);
	vector<int> rows, cols;
	for(int i {}; i < n; i++) for(int j {}; j < m; j++) if(!matrix[i][j]) rows.emplace_back(i), cols.emplace_back(j);
	for(int i:rows) for(int j {}; j < m; j++) matrix[i][j] = 0;
    for(int j:cols) for(int i {}; i < n; i++) matrix[i][j] = 0;
}

// LeetCode Code
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows, cols;
        int r = size(matrix), c = size(matrix[0]);
        for(int i {}; i < r; i++) for(int j {}; j < c; j++) if(!matrix[i][j]) rows.insert(i), cols.insert(j);
        for(int i:rows) for(int j {}; j < c; j++) matrix[i][j] = 0;
        for(int j:cols) for(int i {}; i < r; i++) matrix[i][j] = 0;
    }
};
