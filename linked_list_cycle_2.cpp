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
  ListNode *detectCycle(ListNode *head) {
    ListNode * first = head;
    ListNode * second = head;

    while(second->next != NULL && second->next->next != NULL){
        first = first->next;
        second = second->next->next;
        if(first == second)
          break;
    }

    if(second == NULL){ 
        return NULL;
    }

    first = head;
    while(first != second){
        first = first->next;
        second = second->next;
    }
    return second;
  }
};
