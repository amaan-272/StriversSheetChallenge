//CodeStudio code
int maxProfit(vector<int> &value, vector<int> &weight, int n, int w) {
    vector<vector<int>> profits(w+1, vector<int>(n+1));
    for(int i {}; i <= w; i++) {
        for(int j {}; j <= n; j++) {
            if(!i || !j) profits[i][j] = 0;
            else if(i < weight[j-1]) profits[i][j] = profits[i][j-1];
            else profits[i][j] = max(profits[i][j-1], value[j-1]+profits[i-weight[j-1]][j-1]);
        }
    }
    return profits[w][n];
}
