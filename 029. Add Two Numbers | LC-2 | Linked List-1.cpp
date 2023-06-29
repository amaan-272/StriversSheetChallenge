//CodeStudio Code
/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *************************************************************************/
Node *addTwoNumbers(Node *num1, Node *num2) {
    if(!num1) return num2;
    if(!num2) return num1;
    int carry {}, sum {};
    Node *ans = new Node(), *temp = ans;
    while(num1 && num2) {
        sum += num1->data+num2->data+carry;
        Node* temp = new Node(sum%10);
        ans->next = temp;
        ans = ans->next;
        carry = sum/10;
        sum = 0;
        num1 = num1->next;
        num2 = num2->next;
    }
    while(num1) {
        sum += num1->data+carry;
        Node* temp = new Node(sum%10);
        ans->next = temp;
        ans = ans->next;
        carry = sum/10;
        sum = 0;
        num1 = num1->next;
    }
    while(num2) {
        sum += num2->data+carry;
        Node* temp = new Node(sum%10);
        ans->next = temp;
        ans = ans->next;
        carry = sum/10;
        sum = 0;
        num2 = num2->next;
    }
    if(carry) {
        Node* temp = new Node(carry);
        ans->next = temp;
    }
    temp = temp->next;
    return temp;
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
    
    ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
        if(!a) return b;
        if(!b) return a;
        int carry {}, sum {};
        ListNode *ans = new ListNode(), *temp = ans;
        while(a && b) {
            sum = 0;
            sum += a->val + b->val;
            sum += carry;
            ListNode* nc = new ListNode(sum%10);
            ans->next = nc;
            ans = ans->next;
            carry = sum/10;
            a = a->next;
            b = b->next; 
        }
        sum = 0;
        while(a) {
            sum = 0;
            sum += a->val;
            sum += carry;
            ListNode* nc = new ListNode(sum%10);
            ans->next = nc;
            ans = ans->next;
            carry = sum/10;
            a = a->next;
        }
        sum = 0;
        while(b) {
            sum = 0;
            sum += b->val;
            sum += carry;
            ListNode* nc = new ListNode(sum%10);
            ans->next = nc;
            ans = ans->next;
            carry = sum/10;
            b = b->next; 
        }
        if(carry) {
            ListNode* nc = new ListNode(carry);
            ans->next = nc;
        }
        temp = temp->next;
        return temp;
    }
};
