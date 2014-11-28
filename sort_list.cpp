/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
  ListNode *merge(ListNode *first, ListNode *second){

    if(first == NULL){
      return second;
    }
    if(second == NULL){
      return first;
    }

    ListNode *head = new ListNode(0);
    ListNode *p = head;

    while(first != NULL && second != NULL){
      if(first-> val < second->val){
        p->next = first;
        first = first->next;
      }
      else{
        p->next = second;
        second = second->next;
      }
      p = p->next;
    }

    if(first != NULL){
      p->next = first;
    }
    else if(second != NULL){
      p->next = second;
    }

    return head->next;

  }
public:
  ListNode *sortList(ListNode *head) {

    if(head == NULL || head->next == NULL){
      return head;
    }

    ListNode *fast = head;
    ListNode *slow = head;
    while(fast->next != NULL && fast->next->next != NULL){
      slow = slow->next;
      fast = fast->next->next;
    }
    fast = slow;
    slow = slow->next;
    fast->next = NULL;

    fast = sortList(head);
    slow = sortList(slow);
    return merge(fast, slow);

  }
};
