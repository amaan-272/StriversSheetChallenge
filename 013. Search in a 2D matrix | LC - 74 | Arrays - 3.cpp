//CodeStudio Code
bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size(), m = mat[0].size(), low {}, high {m-1};
    while(low<n && high>-1) {
        if(mat[low][high] == target) return true;
        else if(mat[low][high] < target) low++;
        else high--;
    }
    return false;
}

// LeetCode Code
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = size(matrix), cols = size(matrix[0]), row {}, col {cols-1}; 
        while(row<rows && col>-1) {
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) col--;
            else row++;
        }
        return false;
    }
};
