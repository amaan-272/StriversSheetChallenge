//CodeStudio Code
Node* findIntersection(Node *firstHead, Node *secondHead) {
    Node *first = firstHead, *second = secondHead;
    while(first && second && first!=second) {
        first = first->next;
        second = second->next;
        if(first == second) return first;
        if(!first) first = secondHead;
        if(!second) second = firstHead;
    }
    return first;
}

//LeetCode Code
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA, *p2 = headB;
        if(!p1 || !p2) return NULL;
        while (p1 && p2 && p1!=p2) {
            p1 = p1->next;
            p2 = p2->next;
            if(p1 == p2) return p1;
            if(!p1) p1 = headB;
            if(!p2) p2 = headA;
        }
        return p1;
    }
};
