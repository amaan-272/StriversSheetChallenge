//CodeStudio Code
Node* getListAfterReverseOperation(Node *head, int n, int b[]) {
    if(!head || !head->next) return head;
    Node* ans = new Node(0), *prev = ans, *curr, *succ;
    ans->next = head;
    for(int i  {}; i < n; i++) {
        int k = b[i];
        if(!k) continue;
        if(k == 1) {
            prev = prev->next;
            continue;
        }
        int count {k};
        curr = prev->next;
        succ = curr->next;
        while(count != 1) {
            if(!succ) return ans->next;
            curr->next = succ->next;
            succ->next = prev->next;
            prev->next = succ;
            succ = curr->next;  
            count--;
        }
        prev = curr;    
        if(!succ) return ans->next;        
    }   
    return ans->next;
}

//LeetCode
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    ListNode* reverse(ListNode* first, ListNode* last) {
        ListNode* prev = last;
        while(first != last) {
            auto temp = first->next;
            first->next = prev;
            prev = first;
            first = temp;
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto node = head;
        for(int i {}; i < k; i++) {
            if (!node) return head;             
            node = node->next;
        }
        auto newHead = reverse(head, node);
        head->next = reverseKGroup(node, k);
        return newHead;
    }
};
