//CodeStudio Code
#include <bits/stdc++.h>

class LFUCache {
    int capacity;
    int occur;
    unordered_map<int, pair<int,int>> cache;
    unordered_map<int, list<int>> vis;
    unordered_map<int, list<int>::iterator> pos;

public:
    LFUCache(int capacity) : capacity(capacity), occur(0) {}
    
    int get(int key) {
        if(cache.count(key)) {
            int freq {cache[key].second};
            vis[freq].erase(pos[key]);
            freq++;
            vis[freq].push_front(key);
            pos[key] = vis[freq].begin();
            if(vis[occur].empty())
                occur++;
            return cache[key].first;
        }
        return -1;
    }  

    void put(int key, int value) {
        if(cache.count(key)) {
            cache[key].first = value;
            int freq{cache[key].second};
            vis[freq].erase(pos[key]);
            freq++;
            vis[freq].push_front(key);
            pos[key] = vis[freq].begin();
            if(vis[occur].empty())
                occur++;
            return;
        }
        if(capacity == cache.size()) {
            int key = vis[occur].back();
            cache.erase(key);
            pos.erase(key);
            vis[occur].pop_back();
        }
        cache[key] = {value, 1};
        vis[1].push_front(key);
        pos[key] = begin(vis[1]);
        occur = 1;
    }
};

//LeetCode Code
class LFUCache {
public:
    struct node {
        int key {};
        int value {};
        int freq {};
    };
    
    using i = std::list<node>::iterator;
    unordered_map<int, i> hash;
    unordered_map<int, list<node>> nodes; 
    int size {};
    int minFreq {-1};
    
    LFUCache(int capaciy):size(capaciy) {
        hash.reserve(size);
    }

    int get(int key) {
        auto i = hash.find(key);
        if(i == end(hash)) return -1;
        auto& n = i->second;
        int value = n->value, freq = n->freq;
        auto &list = nodes.find(freq)->second;
        list.erase(n);
        if(list.empty()) {
            nodes.erase(freq);
            if(minFreq == freq) minFreq++;
        }
        freq++;
        nodes[freq].push_back({key, value, freq});
        hash[key] = --nodes[freq].end();
        return value;
    }

    void put(int key, int value) {
        if(!size) return;
        auto i = hash.find(key);
        if(i != end(hash)) {
            i->second->value = value;
            get(key);
            return;
        }
        if(hash.size() >= size) {
            auto& list = nodes.find(minFreq)->second;
            int oldKey = cbegin(list)->key;
            list.erase(cbegin(list));
            hash.erase(oldKey);
            if(list.empty() && minFreq != 1) nodes.erase(minFreq);
        }
        nodes[1].push_back({key, value, 1});
        minFreq = 1;
        hash[key] = --nodes[1].end();
    }
};
