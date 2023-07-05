//CodeStudio Code
Node *firstNode(Node *head) {
    Node *slow = head, *fast = head, *tmp = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            while(tmp != slow) {
                slow = slow->next;
                tmp = tmp->next;
            }
            return slow;
        }
    }
    return NULL;
}

//Leetode Code
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next || !head->next->next) return NULL;
        ListNode *fast = head, *slow = head;
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) break;
        }
        if(fast == slow) {
            ListNode* temp = head;
            while(temp != slow) {
                slow = slow->next;
                temp = temp->next;
            }
            return slow;
        }
        return NULL;
    }
};
