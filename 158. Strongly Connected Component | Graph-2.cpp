//CodeStudio Code
#include <bits/stdc++.h>

vector<vector<int>> graph;
vector<int> lowest, ids;
vector<bool> present;
stack<int> nodes;
vector<vector<int>> ans;
int id;

void dfs(int node) {
    lowest[node] = ids[node] = id++;
    nodes.push(node);
    present[node] = true;
    for(int i:graph[node]) {
        if(ids[i] == -1) dfs(i);
        if(present[i]) lowest[node] = min(lowest[node], lowest[i]);
    }
    if(lowest[node] == ids[node]) {
        vector<int> curr;
        int top = -1;
        while(top != node) {
            top = nodes.top();
            nodes.pop();
            present[top] = false;
            curr.push_back(top);
        }
        ans.push_back(curr);
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>>& edges) {
    graph.clear();
    lowest.clear();
    ids.clear();
    present.clear();
    ans.clear();
    id = 0;
    graph.resize(n);
    lowest.resize(n, -1);
    ids.resize(n, -1);
    present.resize(n, false);
    for(auto i:edges) graph[i[0]].push_back(i[1]);
    for(int i {}; i < n; i++) if(ids[i] == -1) dfs(i);
    return ans;
}
