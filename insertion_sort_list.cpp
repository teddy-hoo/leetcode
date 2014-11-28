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
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* preHead = new ListNode(0);
        ListNode* pre;
        ListNode* p;
        ListNode* tmp;
        ListNode* cur = head;
        while(cur){
            for(pre = preHead, p = preHead->next; p != NULL; pre = pre->next, p = p->next){
                if(p->val > cur->val){
                    tmp = cur->next;
                    pre->next = cur;
                    cur->next = p;
                    cur = tmp;
                    break;
                }
            }
            if(p == NULL){
                tmp = cur->next;
                pre->next = cur;
                cur->next = NULL;
                cur = tmp;
            }
        }
        return preHead->next;
    }
};
