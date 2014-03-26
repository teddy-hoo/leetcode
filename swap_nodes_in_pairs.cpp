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
    ListNode *swapPairs(ListNode *head) {
        ListNode* hhead = new ListNode(-1);
        ListNode* pre = hhead;
        ListNode* p = head;
        ListNode* b;
        ListNode* m;
        hhead->next = head;
        while(pre && p && p->next){
            m = p->next;
            
            b = m->next;
            pre->next = m;
            m->next = p;
            p->next = b;
            pre = p;
            p = b;
        }
        return hhead->next;
    }
};
