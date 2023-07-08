//CodeStudio Code
#include <bits/stdc++.h>

class minStack {
private:
    stack<int> mainstack, minstack;

public:
    minStack() {
        
    }
    
    void push(int num) {
        mainstack.push(num);
        if(minstack.empty() || num<=minstack.top()) minstack.push(num);
    }
    
    int pop() {
        if(mainstack.empty()) return -1;
        int topElement = mainstack.top();
        mainstack.pop();
        if(topElement == minstack.top()) minstack.pop();
        return topElement;
    }
    
    int top() {
        if(mainstack.empty()) return -1;
        return mainstack.top();
    }
    
    int getMin() {
        if(minstack.empty()) return -1;
        return minstack.top();
    }
};

//LeetCode Code
class MinStack {
public:
    vector<int> store;
    
    MinStack() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    void push(int val) {
        store.emplace_back(val);
    }
    
    void pop() {
        store.pop_back();
    }
    
    int top() {
        return store.back();
    }
    
    int getMin() {
        return *min_element(begin(store), end(store));
    }
};
