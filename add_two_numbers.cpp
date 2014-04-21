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
        ListNode *result = new ListNode(0);
        ListNode *p, *p1 = l1, *p2 = l2;
        p = result;
        while(p1 && p2){
            sum = p1->val + p2->val + carry;
            if(sum >= 10){
                carry = 1;
                p->next = new ListNode(sum % 10);
            }
            else{
                carry = 0;
                p->next = new ListNode(sum % 10);
            }
            p = p->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        while(p1){
            sum = p1->val + carry;
            if(sum >= 10){
                carry = 1;
                p->next = new ListNode(sum % 10);
            }
            else{
                carry = 0;
                p->next = new ListNode(sum % 10);
            }
            p = p->next;
            p1 = p1->next;
        }
        while(p2){
            sum = p2->val + carry;
            if(sum >= 10){
                carry = 1;
                p->next = new ListNode(sum % 10);
            }
            else{
                carry = 0;
                p->next = new ListNode(sum % 10);
            }
            p = p->next;
            p2 = p2->next;
        }
        if(carry){
            p->next = new ListNode(carry);
        }
        return result->next;
    }
};
