//CodeStudio Code
#include <bits/stdc++.h> 
// Stack class.
class Stack {
private:
    int* stack;
    int last;
    int n;

public:
    
    Stack(int capacity) {
        stack = new int[capacity];
        last = 0;
        n = capacity;
    }

    void push(int num) {
        if(last != n){
            stack[last] = num;
            last++;
        }
    }

    int pop() {
        if(last){
            last--;
            return stack[last];
        }
        return -1;
    }
    
    int top() {
        return last? stack[last-1]:-1;
    }
    
    int isEmpty() {
        return last? 0:1;
    }
    
    int isFull() {
        return (last == n);
    }
    
};

