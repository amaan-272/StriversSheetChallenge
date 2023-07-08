//CodeStudio Code
vector<int> col;

bool ispossible(int node, vector<vector<int>> &mat, int i) {
    for(int j {}; j < mat.size(); j++) if(mat[node][j] && col[j]==i) return false;
    return true;
}

bool solve(int node, vector<vector<int>> &mat, int m) {
    int n = mat.size();
    if(node == n) return true;
    for(int i {1}; i <= m; i++) {
        if(ispossible(node, mat, i) && (col[node]=i) && solve(node+1, mat, m)) return true;
        col[node] = 0;
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int n = mat.size();
    col.clear();
    col.resize(n);
    return solve(0, mat, m) ? "YES":"NO";
}
