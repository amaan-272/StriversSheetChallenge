//CodeStudio Code
#include <bits/stdc++.h>

int minTimeToRot(vector<vector<int>>& grid, int n, int m) {
    vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
    queue<pair<int, int>> rotten;
    int fresh {};
    for(int i {}; i < n; i++)
        for(int j {}; j < m; j++) {
            if(grid[i][j] == 2) rotten.push({i, j});
            else if(grid[i][j] == 1) fresh++;
        }
    int ans {};
    while(!rotten.empty()) {
        int size = rotten.size();
        while(size--) {
            int x = rotten.front().first, y = rotten.front().second;
            rotten.pop();
            for(int i {}; i < 4; i++) {
                int nx = x+dx[i], ny = y+dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                    fresh--;
                }
            }
        }
        if(!rotten.empty()) ans++;
    }
    return fresh? -1:ans;
}

//LeetCode Code
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
        queue<pair<int, int>> rotten;
        int fresh {}, n = size(grid), m = size(grid[0]);
        for(int i {}; i < n; i++)
            for(int j {}; j < m; j++) {
                if(grid[i][j] == 2) rotten.push({i, j});
                else if(grid[i][j] == 1) fresh++;
            }
        int ans {};
        while(!rotten.empty()) {
            int size = rotten.size();
            while(size--) {
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                for(int i {}; i < 4; i++) {
                    int nx = x+dx[i], ny = y+dy[i];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        rotten.push({nx, ny});
                        fresh--;
                    }
                }
            }
            if(!rotten.empty()) ans++;
        }
        return fresh? -1:ans;
    }
};
