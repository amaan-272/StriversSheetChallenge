//CodeStudio Code
#include <bits/stdc++.h> 
class Queue {
public:
    vector<int> q;
    int n {};

    Queue() { }

    bool isEmpty() {
        return n>=q.size();
    }

    void enqueue(int data) {
        q.emplace_back(data);
    }

    int dequeue() {
        return (n>=q.size())? -1:q[n++];
    }

    int front() {
        return (n>=q.size())? -1:q[n];
    }
};
