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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode* pre = new ListNode(0);
        ListNode* newhead = pre;
        pre->next = head;
        ListNode* target = head;
        ListNode* cursor = head;
        
        for(int i = 0; i < n; ++i){
        	cursor = cursor->next;
        }

        while(cursor != NULL){
        	pre = pre->next;
        	target = target->next;
        	cursor = cursor->next;
        }

        pre->next = target->next;
        
        return newhead->next;
    }
};