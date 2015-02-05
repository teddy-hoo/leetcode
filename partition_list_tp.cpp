/**
 * Two pointer solution
 * Time:   O(n)
 * Space:  O(1)
 * Author: Teddy
 * Date:   05-02-2015
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/**
 * pre   1
 * newP  1
 * p     NULL
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        
        if(head == NULL){
            return NULL;
        }
        
        ListNode *newHead = new ListNode(0);
        ListNode *newP = newHead;
        newHead->next = head;
        
        ListNode *pre = newHead;
        ListNode *p = head;
        
        while(p != NULL){
            if(p->val < x){
                if(pre == newP){
                    pre = pre->next;
                    newP = newP->next;
                    p = p->next;
                }
                else{
                    pre->next = p->next;
                    p->next = newP->next;
                    newP->next = p;
                    newP = p;
                    p = pre->next;
                }
            }
            else{
                pre = pre->next;
                p = p->next;
            }
        }
        
        return newHead->next;
    }
};
