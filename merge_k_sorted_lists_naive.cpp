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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        
        ListNode *newList = new ListNode(0);
        ListNode *n = newList;
        ListNode *cur;
        
        int len = lists.size();
        int count = len;
        
        while(count > 0){
            cur = NULL;
            int min = -1;
            for(int i = 0; i < len; i++){
                if(lists[i] != NULL){
                    if(cur == NULL){
                        cur = lists[i];
                        min = i;
                    }
                    else if(cur->val > lists[i]->val){
                        cur = lists[i];
                        min = i;
                    }
                }
            }
            if(min < 0){
                break;
            }
            n->next = cur;
            n = cur;
            lists[min] = lists[min]->next;
            if(lists[min] == NULL){
                count--;
            }
        }
        
        n->next = NULL;
        
        return newList->next;
    }
};
