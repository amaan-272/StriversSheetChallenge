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
void deleteNode(LinkedListNode<int> * node) {
    *node = *(node->next);
}

//LeetCode Code
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        *node = *(node->next);
    }
};
