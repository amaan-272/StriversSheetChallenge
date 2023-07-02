//CodeStudio Code
#include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the LinkedListNode class:
    template <typename T>
    class LinkedListNode {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data) {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/
LinkedListNode<int> *tmp;
bool solve(LinkedListNode<int> *head) {
    if(!head) return true;
    bool ans = solve(head->next)&&(tmp->data == head->data);
    tmp = tmp->next;
    return ans;
}

bool isPalindrome(LinkedListNode<int> *head) {
    tmp = head;
    return solve(head);
}

//LeetCode Code
/**
 * Definition for singly-linked list.
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
    ListNode* temp;
    
    bool solve(ListNode* head) {
        if(!head) return true;
        bool isPal = solve(head->next)&(temp->val==head->val);
        temp = temp->next;
        return isPal;
    }
    
    bool isPalindrome(ListNode* head) {
        temp = head;
        return solve(head);
    }
};
