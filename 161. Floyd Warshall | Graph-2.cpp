//CodeStudio Code
int floydWarshall(int n, int m, int src, int dest, vector<vector<int>>& edges) {
    vector<vector<int>> graph(n+1, vector<int>(n+1, INT_MAX));
    for(int i {}; i < edges.size(); i++) graph[edges[i][0]][edges[i][1]] = edges[i][2];
    for(int i {1}; i <= n; i++) graph[i][i] = 0;
    for(int k {1}; k <= n; k++) for(int i {1}; i <= n; i++) for(int j {1}; j <= n; j++) if(graph[i][k]!=INT_MAX && graph[k][j]!=INT_MAX) graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
    if(graph[src][dest] == INT_MAX) return 1e9;
    return graph[src][dest];
}
