//CodeStudio Code
Node *rotate(Node *head, int k) {
        if(!head || !head->next || !k) return head;
        Node *curr = head;
        int len{1};
        while(curr->next && len++) curr = curr->next;
        curr->next = head;
        k = len-k%len;
        while(k--) curr = curr->next;
        head = curr->next;
        curr->next = nullptr;
        return head; 
}

//LeetCode Code
class Solution {
public:        
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head ||!head->next || !k) return head;
        ListNode *temp = head;
        int count {};
        while(temp) {
            count++;
            temp = temp->next;
        }
        k %= count;
        if(!k) return head;
        int diff {count-k};
        temp = head;
        while(--diff) temp = temp->next;
        ListNode *ans = temp->next;
        temp->next = NULL;
        temp = ans;
        while(temp->next) temp = temp->next;
        temp->next = head;
        return ans;
    }
};
