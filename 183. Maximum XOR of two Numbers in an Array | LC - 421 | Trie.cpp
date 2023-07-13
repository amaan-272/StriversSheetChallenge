//CodeStudio Code
#include <bits/stdc++.h>

struct Node {
    Node* child[2];

    bool contains(int bit) {
        return child[bit] != NULL;
    }

    Node* get(int bit) {
        return child[bit];
    }

    void put(int bit, Node* node) {
        child[bit] = node;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(int num){
        Node* node = root;
        for(int i {31}; i >= 0; i--){
            int bit = (num>>i)&1;
            if(!node->contains(bit)) node->put(bit, new Node());
            node = node->get(bit);
        }
    }

    int getmax(int num){
        Node* node = root;
        int ans {};
        for(int i {31}; i >= 0; i--){
            int bit = (num>>i)&1;
            if(node->contains(1-bit)){
                ans = (1<<i)|ans;
                node = node->get(1-bit);
            } 
            else node = node->get(bit);
            
        }
        return ans;
    }
};

int maximumXor(vector<int> A) {
    Trie trie;
    for(auto i:A) trie.insert(i);
    int ans {};
    for(auto i:A) ans = max(ans, trie.getmax(i));
    return ans;
}

//LeetCode Code
class TrieNode {
public:
    TrieNode* child[2];

    TrieNode() {
        child[0] = nullptr;
        child[1] = nullptr;
    }
};

class Solution {
    TrieNode* newNode;

    void insert(int x, TrieNode* node) {
        TrieNode* t = node;
        for(int j {31}; j >= 0; j--) {
            int bit = (x>>j)&1;
            if(!t->child[bit]) t->child[bit] = new TrieNode();
            t = t->child[bit];
        }
    }

public:
    int findMaximumXOR(vector<int>& nums) {
        newNode = new TrieNode();
        for(auto& i:nums) insert(i, newNode);
        int ans {};
        for(auto i:nums) ans = max(ans, maxXOR(i, newNode));
        return ans;
    }

    int maxXOR(int n, TrieNode* node) {
        TrieNode* t = node;
        int ans {};
        for(int j {31}; j >= 0; j--) {
            int bit = (n>>j)&1;
            if(t->child[!bit]) {
                ans +=(1 << j);
                t = t->child[!bit];
            } else t = t->child[bit];
        }
        return ans;
    }
};
