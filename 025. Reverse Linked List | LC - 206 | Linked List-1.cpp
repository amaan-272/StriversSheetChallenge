//CodeStudio Code
#include <bits/stdc++.h>

/****************************************************************
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
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {
    LinkedListNode<int> *prev = nullptr, *curr = head, *succ = head;
    while(curr) {
        succ = succ->next;
        curr->next = prev;
        prev = curr;
        curr = succ;
    }
    return prev;
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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *curr = NULL, *nxt = head;
        while(nxt){
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
            curr->next = prev;
        }
        return curr;
    }
};
