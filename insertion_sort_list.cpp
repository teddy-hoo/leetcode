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
        ListNode* hhead = new ListNode(0);
        hhead->next = head;
        ListNode* pre;
        ListNode* p;
        if(!head)
            return NULL;
        ListNode* tmp = head;
        ListNode* cur = head->next;
        bool flag = false;
        while(cur){
            for(pre = hhead, p = hhead->next; p != cur; pre = pre->next, p = p->next){
                if(p->val > cur->val){
                    tmp->next = cur->next;
                    pre->next = cur;
                    cur->next = p;
                    flag = true;
                    break;
                }
            }
            if(flag){
                cur = tmp->next;
                flag = false;
            }
            else{
                tmp = tmp->next;
                cur = tmp->next;
            }
        }
        return hhead->next;
    }
};
