//CodeStudio Code 
#include <bits/stdc++.h>

class Ds {
private:
    vector<int> rank, size, parent;

public:
    Ds(int n) : rank(n+1, 0), size(n+1, 1), parent(n+1) {
        iota(begin(parent), end(parent), 0);
    }

    int findPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findPar(parent[node]);
    }

    void Union(int u, int v) {
        int valu = findPar(u), valv = findPar(v);
        if(valu == valv) return;
        if(rank[valu] > rank[valv]) parent[valv] = valu;
        else if(rank[valu] < rank[valv]) parent[valu] = valv;
        else {
            parent[valu] = valv;
            rank[valv]++;
        }
    }
};

bool compare(const vector<int>& a, const vector<int>& b) {
    return a[2] < b[2];
}

int kruskalMST(int n, int m, vector<vector<int>>& graph) {
    sort(begin(graph), end(graph), compare);
    int ans {};
    Ds ds(n);
    for(const auto& i:graph) {
        if(ds.findPar(i[0]) != ds.findPar(i[1])) {
            ans += i[2];
            ds.Union(i[0], i[1]);
        }
    }
    return ans;
}
