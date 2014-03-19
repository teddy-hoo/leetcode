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
    ListNode *deleteDuplicates(ListNode *head) {
        map<int, int> count;
        ListNode* p = head;
        ListNode* pre = new ListNode(0);
        pre->next = p;
        while(p != NULL){
            if(count.find(p->val) == count.end()){
                count.insert(pair<int, int>(p->val, 1));
                pre = p;
                p = p->next;
                continue;
            }
            if(count[p->val] >= 1){
                pre->next = p->next;
                p = p->next;
                continue;
            }
        }
        return head;
    }
};
