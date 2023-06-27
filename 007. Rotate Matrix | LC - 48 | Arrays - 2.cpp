//CodeStudio Code
#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m) {
    int up {}, down {n-1}, left {}, right {m-1};
    if(!down && !right) return;
    while(left<right && up<down) {
        int tmp {mat[up][up]};
        for(int i {left+1}; i <= right; i++) swap(tmp, mat[up][i]);
        for(int i {up+1}; i <= down; i++) swap(tmp, mat[i][right]);
        for(int i {right-1}; i >= left; i--) swap(tmp, mat[down][i]);
        for(int i {down-1}; i >= up; i--) swap(tmp, mat[i][left]);
        up++;
        down--;
        left++;
        right--;
    }    
}

//LeetCode Code
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    void rotate(vector<vector<int>>& matrix) {
        int n = size(matrix);
        for(int i {}; i < (n+1)/2; i++) {
            for(int j {}; j < n/2; j++){
                int temp {matrix[n-j-1][i]};
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
};
