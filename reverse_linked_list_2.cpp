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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m == n)
            return head;
        int index = 0;
        ListNode *ppm = NULL;
        ListNode *pm = NULL;
        //ListNode *pn = NULL;
        ListNode *p = head;
        ListNode *q = NULL;
        ListNode *newnode = new ListNode(0);
        p = newnode;
        p->next = head;
        while(pm == NULL){
            if(index == m - 1){
                ppm = p;
                pm = p->next;
            }
            //if(index == n){
            //    pn = p;
            //}
            index++;
            p = p->next;
        }
        index = 1;
        while(index <= n - m){
            p = pm->next;
            q = ppm->next;
            ppm->next = p;
            pm->next = p->next;
            p->next = q;
            index++;
        }
        return newnode->next;
    }
};
