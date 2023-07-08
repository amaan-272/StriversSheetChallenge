//CodeStudio Code
vector<vector<int>> ans;

void solve(int n, vector<int>& board, vector<bool>& done, vector<bool>& l2r, vector<bool>& r2l, int row) {
    if(row == n) {
        ans.push_back(board);
        return;
    }
    for(int col {}; col < n; col++) {
        if(!done[col] && !l2r[row+col] && !r2l[row-col+n-1]) {
            board[row*n+col] = 1;
            done[col] = true;
            l2r[row+col] = true;
            r2l[row-col+n-1] = true;
            solve(n, board, done, l2r, r2l, row+1);
            board[row*n+col] = 0;
            done[col] = false;
            l2r[row+col] = false;
            r2l[row-col+n-1] = false;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<int> board(n*n, 0);  
    vector<bool> done(n, false), l2r(2*n-1, false), r2l(2*n-1, false);  
    solve(n, board, done, l2r, r2l, 0);
    return ans;
}

//LeetCode Code
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    vector<vector<string>> ans;
    
    bool isValid(vector<string> &board, int row, int col) {
        for(int i {row}; i >= 0; i--) if(board[i][col] == 'Q') return false;
        for(int i {row}, j {col}; i>=0 && j>=0; i--, j--) if(board[i][j] == 'Q') return false;
        for(int i {row}, j {col}; i>=0 && j<size(board); i--, j++) if(board[i][j] == 'Q') return false;
        return true;
    }
    
    void dfs(vector<string> &board, int row){
        int n = size(board);
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int i {}; i < n; i++){
            if(isValid(board, row, i)){
                board[row][i] = 'Q';
                dfs(board, row+1);
                board[row][i] = '.';
            }
        }
    }
        
    vector<vector<string>> solveNQueens(int n) {
	    vector<string> board(n, string(n,'.'));
        dfs(board, 0);
        return ans;
    }
};
