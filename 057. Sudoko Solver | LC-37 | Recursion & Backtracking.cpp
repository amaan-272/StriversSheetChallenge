//CodeStudio Code
bool isvalid(int row, int col, int c, int matrix[9][9]){
    for(int i {}; i < 9; i++){
        if(matrix[i][col] == c) return false;
        if(matrix[row][i] == c) return false;
        if(matrix[3*(row/3)+i/3][3*(col/3)+i%3] == c) return false;
    }
    return true;
}

bool solve(int matrix[9][9]){
    for(int i {}; i < 9; i++)
        for(int j {}; j < 9; j++){
            if(!matrix[i][j]){
                for(int k {1}; k <= 9; k++){
                    if(isvalid(i, j, k, matrix)){
                        matrix[i][j] = k;
                        if(solve(matrix)) return true;
                        else matrix[i][j] = 0;
                    }  
                }
            return false;
        }
    }
    return true;
}

bool isItSudoku(int matrix[9][9]) {
    return solve(matrix);
}

//LeetCode Code
class Solution {
public:
    bool isvalid(int row, int col, int c, vector<vector<char>>& board){
        for(int i {}; i < 9; i++){
            if(board[i][col] == c) return false;
            if(board[row][i] == c) return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == c) return false;
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board){
        for(int i {}; i < 9; i++) {
            for(int j {}; j < 9; j++){
                if(board[i][j] == '.'){
                    for(int k {'1'}; k <= '9'; k++){
                        if(isvalid(i, j, k, board)){
                            board[i][j] = k;
                            if(solve(board)) return true;
                            else board[i][j] = '.';
                        }  
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);  
    }
};
