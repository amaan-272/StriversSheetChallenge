//CodeStudio Code
int oldColor;

void fill(vector<vector<int>>& image, int x, int y, int newColor) {
    if(x<0 || x>=image.size() || y<0 || y>=image[0].size() || image[x][y]!=oldColor) return;
    image[x][y] = newColor;
    fill(image, x-1, y, newColor);
    fill(image, x+1, y, newColor);
    fill(image, x, y-1, newColor);
    fill(image, x, y+1, newColor);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int x, int y, int newColor) {
    if(image[x][y] == newColor) return image;
    oldColor = image[x][y];
    fill(image, x, y, newColor);
    return image;
}

//LeetCode Code
class Solution {
public:
    void bfs(vector<vector<int>>& image, int r, int c, int val, int color) {
        if(r<0 || r>=size(image) || c<0 || c>=size(image[0]) || image[r][c]!=val) return;
        image[r][c] = color;
        bfs(image, r-1, c, val, color);
        bfs(image, r+1, c, val, color);
        bfs(image, r, c-1, val, color);
        bfs(image, r, c+1, val, color);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] != color) bfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
};
