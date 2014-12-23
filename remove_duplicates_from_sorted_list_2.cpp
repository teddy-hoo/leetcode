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
        if(!head || !head->next){
        	return head;
        }
        
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *pre = newHead;
        ListNode *fast = head->next;
        ListNode *slow = head;

        int count = 1;
        while(fast != NULL){
        	if(fast->val == slow->val){
        		count++;
        		fast = fast->next;
        	}
        	else{
        		if(count > 1){
        			pre->next = fast;
        			slow = fast;
        			fast = fast->next;
        			count = 1;
        		}
        		else{
        			pre = slow;
        			slow = fast;
        			fast = fast->next;
        		}
        	}
        }

        if(count > 1){
        	pre->next = fast;
        }

        return newHead->next;
    }
};