//CodeStudio Code
#include <bits/stdc++.h>

class Trie {
public:
    class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
        bool isWord;
        TrieNode() {
            isWord = false;
        }
    };

    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;
        for(char c:word) {
            if(curr->children.find(c) == curr->children.end()) curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }
        curr->isWord = true;
    }

    TrieNode* searchPrefix(string prefix) {
        TrieNode* curr = root;
        for(char c:prefix) {
            if(curr->children.find(c) == curr->children.end()) return nullptr;
            curr = curr->children[c];
        }
        return curr;
    }

    bool search(string word) {
        TrieNode* node = searchPrefix(word);
        return node != nullptr && node->isWord;
    }

    bool startsWith(string prefix) {
        TrieNode* node = searchPrefix(prefix);
        return node != nullptr;
    }
};

//LeetCode Code
class Trie {
public:
    Trie* children[26] = {};
    bool isWord = false;
    
    Trie() {
        
    }
    
    void insert(string word) {
        Trie* cur = this;
        for(char& c:word) {
            c -= 'a';
            if(!cur->children[c]) cur->children[c] = new Trie();
            cur = cur->children[c];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        Trie* cur = this;
        for(char& c:word) {
            c -= 'a';
            if(!cur->children[c]) return false;
            cur = cur->children[c];
        }
        return cur->isWord;
    }
    
    bool startsWith(string prefix) {
        Trie* cur = this;
        for(char& c:prefix) {
            c -= 'a';
            if(!cur->children[c]) return false;
            cur = cur->children[c];
        }
        return true;
    }
};
