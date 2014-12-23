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
	int getLength(ListNode *l){
		int len = 1;
		while(l->next != NULL){
			l = l->next;
			len++;
		}
		return len;
	}
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA){
			return headA;
		}

		if(!headB){
			return headB;
		}

		int lenA = getLength(headA);
		int lenB = getLength(headB);

		int distance = lenA > lenB ? lenA - lenB : lenB - lenA;
		int count = 0;
		ListNode *p = lenA > lenB ? headA : headB;
		ListNode *pp = lenA > lenB ? headB : headA;

		while(p != NULL){
			if(count >= distance){
				if(p == pp){
					return p;
				}
				pp = pp->next;
			}
			p = p->next;
			count++;
		}
		return p;
    }
};