//CodeStudio Code
#include <bits/stdc++.h>

class TrieNode {
public:
    TrieNode* children[26];
    int endwith;
    int countprefix;
    TrieNode() {
        endwith = 0;
        countprefix = 0;
        memset(children, 0, sizeof(children));
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }

    void InsertWord(TrieNode* root, string word) {
        if(!word.size()) {
            root->countprefix++;
            root->endwith++;
            return;
        }
        int index = word[0]-'a';
        TrieNode* child;
        if(root->children[index] != NULL) child = root->children[index];
        else {
            TrieNode* newTrieNode = new TrieNode();
            root->children[index] = newTrieNode;
            child = root->children[index];
        }
        root->countprefix++;
        InsertWord(child, word.substr(1));
    }

    int CountWords(TrieNode* root, string word) {
        if(!word.size()) return root->endwith;
        int index = word[0]-'a';
        TrieNode* child;
        if(root->children[index] != NULL) child = root->children[index];
        else return 0;
        return CountWords(child, word.substr(1));
    }

    int CountWord_withPrefix(TrieNode* root, string word) {
        if(!word.size()) return root->countprefix;
        int index = word[0]-'a';
        TrieNode* child;
        if(root->children[index] != NULL) child = root->children[index];
        else return 0;
        return CountWord_withPrefix(child, word.substr(1));
    }

    void RemoveWords(TrieNode* root, string word) {
        if(!word.size()) {
            root->countprefix--;
            root->endwith--;
            return;
        }
        int index = word[0]-'a';
        TrieNode* child;
        if(root->children[index] != NULL) {
            root->countprefix--;
            child = root->children[index];
        } 
        else return;
        RemoveWords(child, word.substr(1));
    }

    void insert(string& word) {
        InsertWord(root, word);
    }

    int countWordsEqualTo(string& word) {
        return CountWords(root, word);
    }

    int countWordsStartingWith(string& word) {
        return CountWord_withPrefix(root, word);
    }

    void erase(string& word) {
        RemoveWords(root, word);
    }
};
