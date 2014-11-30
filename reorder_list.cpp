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
  ListNode *seperate(ListNode *head){

    ListNode *fast = head;
    ListNode *slow = head;

    while(fast->next != NULL && fast->next->next != NULL){
      slow = slow->next;
      fast = fast->next->next;
    }

    fast       = slow;
    slow       = slow->next;
    fast->next = NULL;

    return slow;

  }

  ListNode* reverse(ListNode *head){

    ListNode *newList = new ListNode(0);
    ListNode *p   = newList;

    while(head != NULL){
      ListNode *tmp = head->next;
      head->next    = p->next;
      p->next       = head;
      head          = tmp;
    }

    head = newList->next;
    delete(newList);

    return head;
  }

  ListNode *merge(ListNode *first, ListNode *second){

    ListNode *head = first;
    ListNode *tmp;

    while(second != NULL){
      tmp          = second->next;
      second->next = first->next;
      first->next  = second;
      first        = second->next;
      second       = tmp;
    }

    return head;
  }
public:
  void reorderList(ListNode *head) {

    if(head == NULL || head->next == NULL){
      return;
    }

    ListNode *middle  = seperate(head);
    ListNode *newList = reverse(middle);
    head              = merge(head, newList);
  }
};
