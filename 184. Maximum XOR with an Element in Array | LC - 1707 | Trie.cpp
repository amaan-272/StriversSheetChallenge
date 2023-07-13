//CodeStudio Code
#include <bits/stdc++.h>

struct Node {
    Node* links[2];
    bool containsKey(int bit) {
        return links[bit] != NULL;
    }
    void put(int bit, Node* node) {
        links[bit] = node;
    }
    Node* get(int bit) {
        return links[bit];
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    void insert(int num) {
        Node* node = root;
        for(int i = 30; i >= 0; i--) {
            int bit = (num>>i)&1;
            if(!node->containsKey(bit)) node->put(bit, new Node());
            node = node->get(bit);
        }
    }
    int max_XOR(int num) {
        Node* node = root;
        int ans {};
        for(int i = 30; i >= 0; i--) {
            int bit =(num >> i) & 1;
            if(node->containsKey(!bit)) {
                ans = ans ^(1 << i);
                node = node->get(!bit);
            } 
			else node = node->get(bit);
        }
        return ans;
    }
};

vector<int> maxXorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    int n = queries.size(),m = arr.size(), j = 0;
    Trie trie;
    vector<int> ans(n, -1);
    for(int i {}; i < n; i++) queries[i].push_back(i);    
    sort(begin(arr), end(arr));
    sort(begin(queries), end(queries), [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1];});
    for(int i {}; i < n; i++) {
        while(j < m && arr[j] <= queries[i][1]) trie.insert(arr[j++]);
        if(j) ans[queries[i][2]] = trie.max_XOR(queries[i][0]);
    }
    return ans;
}

//LeetCode Code
struct Node {
    Node* links[2];
    bool containsKey(int bit) {
        return links[bit] != NULL;
    }
    void put(int bit, Node* node) {
        links[bit] = node;
    }
    Node* get(int bit) {
        return links[bit];
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    void insert(int num) {
        Node* node = root;
        for(int i = 30; i >= 0; i--) {
            int bit = (num>>i)&1;
            if(!node->containsKey(bit)) node->put(bit, new Node());
            node = node->get(bit);
        }
    }
    int max_XOR(int num) {
        Node* node = root;
        int ans {};
        for(int i = 30; i >= 0; i--) {
            int bit =(num >> i) & 1;
            if(node->containsKey(!bit)) {
                ans = ans ^(1 << i);
                node = node->get(!bit);
            } 
			else node = node->get(bit);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size(), m = nums.size(), j = 0;
        Trie trie;
        vector<int> ans(n, -1);
        for(int i {}; i < n; i++) queries[i].push_back(i);    
        sort(begin(nums), end(nums));
        sort(begin(queries), end(queries), [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1];});
        for(int i {}; i < n; i++) {
            while(j < m && nums[j] <= queries[i][1]) trie.insert(nums[j++]);
            if(j) ans[queries[i][2]] = trie.max_XOR(queries[i][0]);
        }
        return ans;
    }
};
