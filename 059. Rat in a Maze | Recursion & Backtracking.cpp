//CodeStudio Code
#include <bits/stdc++.h> 

vector<vector<int>> ans;

void solve(vector<vector<int>>& maze, vector<int>& path, vector<vector<bool>>& vis, int row, int col) {
  int n = maze.size();
  if(col==n-1 && row==n-1) {
    ans.push_back(path);
    return;
  }
  int rdir[] = {0, 0, 1, -1}, cdir[] = {1, -1, 0, 0};
  for(int i {}; i < 4; i++) {
    int nrow {row+rdir[i]}, ncol {col+cdir[i]};
    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && !vis[nrow][ncol] && maze[nrow][ncol]) {
      vis[nrow][ncol] = true;
      path[n*nrow+ncol] = 1;
      solve(maze, path, vis, nrow, ncol);
      vis[nrow][ncol] = false;
      path[n*nrow+ncol] = 0;
    }
  }
}

vector<vector<int>> ratInAMaze(vector<vector<int>>& maze, int n) {
  ans.clear();
  vector<vector<bool>> vis(n, vector<bool>(n, 0));
  vector<int> path(n*n, 0);
  vis[0][0] = 1;
  path[0] = 1;
  solve(maze, path, vis, 0, 0);
  return ans;
}
