//CodeStudio Code
#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
    int row = grid.size(), col = grid[0].size();
    for(int i {}; i < row; i++){
	    for(int j {}; j < col; j++){
	        if(!i && j) grid[i][j] += grid[i][j-1];
            if(i && !j) grid[i][j] += grid[i-1][j];
            if(i && j) grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
	    }
    }
    return grid[row-1][col-1];
}

//LeetCode Code
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = size(grid), col = size(grid[0]);
        for(int i {}; i < row; i++){
	        for(int j {}; j < col; j++){
	            if(!i&& j) grid[i][j] += grid[i][j-1];
	            if(i && !j) grid[i][j] += grid[i-1][j];
	            if(i && j) grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
	        }
        }
        return grid[row-1][col-1];
    }
};
