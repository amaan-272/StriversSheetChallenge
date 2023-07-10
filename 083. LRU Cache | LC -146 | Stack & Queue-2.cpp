//CodeStudio Code
#include <bits/stdc++.h>

class LRUCache {
public:
    class Node {
    public:
        int key;
        int value;
        Node* next;
        Node* prev;
        
        Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    unordered_map<int, Node*> storage;
    int capacity;

public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    int get(int key) {
        if (storage.find(key) != storage.end()) {
            Node* node = storage[key];
            removeNode(node);
            addToFront(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if(storage.find(key) != end(storage)) {
            Node* node = storage[key];
            node->value = value;
            removeNode(node);
            addToFront(node);
        } 
        else {
            if(storage.size() == capacity) {
                Node* nodeToRemove = tail->prev;
                removeNode(nodeToRemove);
                storage.erase(nodeToRemove->key);
                delete nodeToRemove;
            }
            Node* newNode = new Node(key, value);
            addToFront(newNode);
            storage[key] = newNode;
        }
    }
};

//LeetCode Code
class LRUCache {
public:
    class Node {
    public:
        int key;
        int value;
        Node* next;
        Node* prev;
        Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
    };

    Node* head, *tail;
    unordered_map<int, Node*> storage;
    int capacity;

public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    int get(int key) {
        if(storage.find(key) != end(storage)) {
            Node* node = storage[key];
            removeNode(node);
            addToFront(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if(storage.find(key) != end(storage)) {
            Node* node = storage[key];
            node->value = value;
            removeNode(node);
            addToFront(node);
        } 
        else {
            if(size(storage) == capacity) {
                Node* nodeToRemove = tail->prev;
                removeNode(nodeToRemove);
                storage.erase(nodeToRemove->key);
                delete nodeToRemove;
            }
            Node* newNode = new Node(key, value);
            addToFront(newNode);
            storage[key] = newNode;
        }
    }
};
