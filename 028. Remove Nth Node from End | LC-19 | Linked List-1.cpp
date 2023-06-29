//CodeStudio Code
/*
class Node {
public:
    int data;
    Node *next;
    Node() {
        this->data = 0;
        next = NULL;
    }
    Node(int data) {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};
*/
Node* removeKthNode(Node* head, int K) {
    Node *first = head, *second = head;
    for(int i {}; i < K; i++) first = first->next;
    if(!first) return head->next;
    while(first->next) {
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    return head;
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first = head, *second = head;
        for(int i {}; i < n; i++) first = first->next;
        if(!first) return head->next;
        while (first->next) first = first->next, second = second->next;
        second->next = second->next->next;
        return head;
    }
};
