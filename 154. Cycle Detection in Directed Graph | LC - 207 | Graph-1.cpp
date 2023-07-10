//CodeStudio Code
#include <bits/stdc++.h>

bool detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges) {
  vector<vector<int>> graph(n+1);
  for(int i {}; i < edges.size(); i++) graph[edges[i].first].push_back(edges[i].second);
  vector<int> indegree(n+1, 0);
  for(int i {1}; i <= n; i++) for(auto j:graph[i]) indegree[j]++;
  int cnt {};
  queue<int> q;
  for(int i {1}; i <= n; i++) if(!indegree[i]) q.push(i);
  while(!q.empty()) {
    int node = q.front();
    q.pop();
    cnt++;
    for(auto i:graph[node]) {
      indegree[i]--;
      if(!indegree[i]) q.push(i);
    }
  }
  return cnt!=n;
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
