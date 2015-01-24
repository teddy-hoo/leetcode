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
    ListNode *insertionSortList(ListNode *head) {
        
        if(head == NULL){
            return head;
        }
        
        ListNode *newHead = new ListNode(0);
        
        newHead->next = head;
        
        ListNode *pre = head;
        ListNode *cur = head->next;
        
        while(cur != NULL){
            ListNode *p = newHead;
            ListNode *c = newHead->next;
            while(c != cur && c->val < cur->val){
                p = p->next;
                c = c->next;
            }
            if(c != cur){
                pre->next = cur->next;
                p->next = cur;
                cur->next = c;
                cur = pre->next;
            }
            else{
                pre = pre->next;
                cur = cur->next;
            }
        }
        
        return newHead->next;
    }
};
