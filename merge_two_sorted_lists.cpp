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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        while(p1 && p2 ){
            if(p1->val <= p2->val){
                p->next = p1;
                p = p->next;
                p1 = p1->next;
            }
            else{
                p->next = p2;
                p = p->next;
                p2 = p2->next;
            }
        }
        while(p1){
            p->next = p1;
            p = p->next;
            p1 = p1->next;
        }
        while(p2){
            p->next = p2;
            p = p->next;
            p2 = p2->next;
        }
        return head->next;
    }
};
