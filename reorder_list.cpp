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
    void reorderList(ListNode *head) {
        if(!head)
            return;
        vector<ListNode*> cache;
        ListNode* p;
        ListNode* newhead = new ListNode(0);
        int i, j;
        for(p = head; p != NULL; p = p->next){
            cache.push_back(p);
        }
        for(p = newhead, i = 0, j = cache.size() - 1; i < j; ++i, --j){
            p->next = cache[i];
            p = p->next;
            p->next = cache[j];
            p = p->next;
        }
        if(i == j){
            p->next = cache[i];
            p = p->next;
        }
        p->next = NULL;
        head = newhead->next;
    }
};
