//CodeStudio Code
vector<vector<int>> graph;
vector<bool> vis;
    

bool dfs(int node, int parent) {
    vis[node] = true;
    for(int i:graph[node]) {
        if(!vis[i]) { if(dfs(i, node)) return true; }
        else if(i != parent) return true;
    }
    return false;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m) {
    graph.clear();
    vis.clear();
    graph.resize(n+1);
    vis.resize(n+1, false);
    for(int i {}; i < m; i++) graph[edges[i][0]].push_back(edges[i][1]);
    for(int i {}; i < m; i++) graph[edges[i][1]].push_back(edges[i][0]);
    for(int i {1}; i < n+1; i++) if(!vis[i] && dfs(i, -1)) return "Yes";
    return "No";
}

//LeetCode Code
class Solution {
public:
    vector<vector<int>> graph;
    vector<int> visited, req;
    
    bool dfs(int node) {
        visited[node] = 1;
        req[node] = 1;
        bool cycle = false; 
        for(int i {}; i < size(graph[node]); i++) {
            if(req[graph[node][i]]) return true;
            if(!visited[graph[node][i]]) {
                cycle = dfs(graph[node][i]);
                if(cycle) return true;
            }
        }
        req[node] = 0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        visited.resize(numCourses, 0);
        req.resize(numCourses, 0);
        queue<int> q;
        int course, preq;
        for(int i {}; i < size(prerequisites); i++) {
            course = prerequisites[i][0];
            preq = prerequisites[i][1];
            graph[preq].push_back(course);
            q.push(preq);
        }  
        bool cycle = false;
        for(int i {}; i < numCourses; i++) {
            if(!visited[i]) {
                req[i] = 1;
                cycle = dfs(i);
                if(cycle)  return false;
            }
        }
        return true;
    }
};
