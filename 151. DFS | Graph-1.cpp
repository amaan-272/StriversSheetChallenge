//CodeStudio Code
void dfs(int node, vector<int> graph[], vector<bool>& vis, vector<int>& nodes) {
    vis[node] = true;
    nodes.emplace_back(node);
    for(int i:graph[node]) if(!vis[i]) dfs(i, graph, vis, nodes);
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>>& edges) {
    vector<int> graph[V];
    for(auto& i:edges) graph[i[0]].emplace_back(i[1]);    
    for(auto& i:edges) graph[i[1]].emplace_back(i[0]);
    vector<bool> vis(V, false);
    vector<vector<int>> ans;
    for(int i {}; i < V; ++i) {
        if(!vis[i]) {
            vector<int> nodes;
            dfs(i, graph, vis, nodes);
            ans.push_back(nodes);
        }
    }
    return ans;
}
