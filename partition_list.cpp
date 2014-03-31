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
    ListNode *partition(ListNode *head, int x) {
        vector<ListNode*> store;
        if(!head)
            return head;
        ListNode* p = head;
        ListNode* hhead = new ListNode(0);
        hhead->next = head;
        ListNode* pre = hhead;
        while(p){
            if(p->val >= x){
                store.push_back(p);
                p = p->next;
                pre->next = p;
            }
            else{
                pre = p;
                p = p->next;
            }
        }
        for(int i = 0; i < store.size(); i ++){
            pre->next = store[i];
            pre = pre->next;
            pre->next = NULL;
        }
        return hhead->next;
    }
};
