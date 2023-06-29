//CodeStudio Code
#include <bits/stdc++.h>

/************************************************************
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;
        Node(T data) {
            next = NULL;
            this->data = data;
        }
        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };
************************************************************/
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second) {
    if(!first) return second;
    if(!second) return first;
    if(first->data <= second->data) {
        first->next = sortTwoLists(first->next, second);
        return first;
    }    
    else {
        second->next = sortTwoLists(second->next, first);
        return second; 
    }
}

//LeetCode Code
/**
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        if(list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
