//CodeStudio Code
bool detectCycle(Node *head) {
	if(!head) return false;
    Node *fast = head, *slow = head;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) return true;
    }
    return false;
}

//LeetCode Code
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode *fast = head, *slow = head;
        while(fast && fast->next)  {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) return true;
        }
        return false;
    }
};
