//CodeStudio Code
void dfs(int **arr, vector<vector<int>>&visited, int row, int col, int n, int m) {
   if(row<0 || row>=n || col<0 || col>=m || visited[row][col] || !arr[row][col]) return;
   visited[row][col] = 1;
   int dir[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
   for(int i {}; i < 8; i++) dfs(arr, visited, row+dir[i][0], col+dir[i][1], n, m);
}

int getTotalIslands(int** arr, int n, int m) {
   vector<vector<int>> visited(n, vector<int>(m, 0));
   int ans {};
   for(int i {}; i < n; i++) {
      for(int j {}; j < m; j++) {
         if(arr[i][j] && !visited[i][j]) {
            ans++;
            dfs(arr, visited, i, j, n, m);
         }
      }
   }
   return ans;
}

//LeetCode Code
class Solution {
public:
    void solve(vector<vector<char>>& grid, int i, int j, int n, int m) {
        if(i<0 || j<0 || i==n || j==m || grid[i][j]=='0') return;
        grid[i][j] = '0';
        solve(grid, i+1, j, n, m);
        solve(grid, i, j+1, n, m);
        solve(grid, i-1, j, n, m);
        solve(grid, i, j-1, n, m);
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0, i, j;
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    ans++; solve(grid, i, j, n, m);
                }
            }
        }
        return ans;
    }
};
