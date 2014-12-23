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
	ListNode* reverse(ListNode* pre, ListNode* tail){
		ListNode *p = pre->next;
		ListNode *head = pre->next;
		pre->next = tail;
		while(p != tail){
			ListNode *tmp = p->next;
			p->next = pre->next;
			pre->next = p;
			p = tmp;
		}
		return head;
	}
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
    	if(!head || k < 2){
    		return head;
    	}

        ListNode *newHead = new ListNode(0);
        newHead->next = head;

        ListNode *pre = newHead;
        ListNode *tail = head;

        int counter = 0;
        while(tail != NULL){
        	if(counter != k){
        		tail = tail->next;
        		counter++;
        	}
        	else{
        		pre = reverse(pre, tail);
        		counter = 0;
        	}
        }

        if(counter == k){
        	reverse(pre, NULL);
        }

        return newHead->next;
    }
};