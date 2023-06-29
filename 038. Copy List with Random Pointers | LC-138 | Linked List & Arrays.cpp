//CodeStudio Code
#include <bits/stdc++.h>

/*************************************************************
    template <typename T>   
    class LinkedListNode {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data) {
            this->data = data;
            this->next = NULL;
        }
    };
*************************************************************/
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head) {
    unordered_map<LinkedListNode<int>*, LinkedListNode<int>*> ans;
    LinkedListNode<int> *tmp = head;
    while(tmp) {
        ans[tmp] = new LinkedListNode<int>(tmp->data);
        tmp = tmp->next;
    }
    tmp = head;
    while(tmp) {
        ans[tmp]->next = ans[tmp->next];
        ans[tmp]->random = ans[tmp->random];
        tmp = tmp->next;
    }
    return ans[head];
}

//LeetCode Code
/*
class Node {
public:
    int val;
    Node* next;
    Node* random;  
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node *temp = head, *front = head;
        while(temp) {
            Node *copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = copy->next;
        }
        temp = head;
        while(temp) {
            if(temp->random) temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        temp = head;
        Node *newHead = temp->next, *copy = newHead;
        while(temp) {
            temp->next=  newHead->next;
            if(temp->next) newHead->next = temp->next->next;
            else newHead->next = nullptr;
            temp = temp->next;
            newHead = newHead->next;
        }
        return copy;
    }
};
