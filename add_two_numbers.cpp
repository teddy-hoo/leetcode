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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        
        int carry = 0;
        int sum;
        ListNode *pre = new ListNode(0);
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        pre->next = p1;
        
        while(p1 != NULL && p2 != NULL){
            sum = p1->val + p2->val + carry;
            sum > 9? (sum -= 10, carry = 1): carry = 0;
            p1->val = sum;
            pre = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        while(p1 != NULL && carry != 0){
            sum = p1->val + carry;
            sum > 9? (sum -= 10, carry = 1): carry = 0;
            p1->val = sum;
            pre = p1;
            p1 = p1->next;
        }
        p1 = pre;
        if(carry == 0 && p2 != NULL){
            p1->next = p2;
            return l1;
        }
        while(p2 != NULL && carry != 0){
            sum = p2->val + carry;
            sum > 9? (sum -= 10, carry = 1): carry = 0;
            p2->val = sum;
            p1->next = p2;
            p1 = p1->next;
            p2 = p2->next;
        }
        if(carry){
            p1->next = new ListNode(carry);
        }
        return l1;
    }
};
