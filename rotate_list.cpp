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
    ListNode *rotateRight(ListNode *head, int k) {
        int length = 0;
        ListNode* p = head;
        ListNode* q = head;
        ListNode* tmp;
        while(p){
            length++;
            tmp = p;
            p = p->next;
        }
        p = tmp;
        if(!head || k % length == 0)
            return head;
        for(int i = 0; i < length - k % length; i++){
            p->next = q;
            tmp = q->next;
            q->next = NULL;
            q = tmp;
            p = p->next;
        }
        return q;
    }
};
