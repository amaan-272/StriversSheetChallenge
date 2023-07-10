//CodeStudio Code
#include <bits/stdc++.h>

bool isGraphBirpatite(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> color(n, -1);
    queue<int> q;
    q.push(0);
    color[0] = 1;
    while(!q.empty()) {
        int i = q.front();
        q.pop();
        if(edges[i][i]) return false;
        for(int j {}; j < n; j++) {
            if(edges[i][j] && color[j] == -1) {
                color[j] = 1-color[i];
                q.push(j);
            }
            else if(edges[i][j] && color[j]==color[i]) return false;
        }
    }
    return true;
}

//LeetCode Code
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = size(graph);
        vector<int> colors(n, -1);
        for(int i {}; i < n; ++i) {
            if(colors[i] != -1) continue;
            queue<int> q;
            q.push(i);
            colors[i] = 1;
            while(!q.empty()) {
                int curr = q.front();
                q.pop();
                for(auto& j:graph[curr]) {
                    if(colors[j] == colors[curr]) return false;
                    if(colors[j] == -1) {
                        colors[j] = colors[curr] ^ 1;
                        q.push(j);
                    }
                }
            }
        }
        return true;
    }
};
