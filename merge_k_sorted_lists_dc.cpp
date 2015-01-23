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
	ListNode *mergeTwo(ListNode *left, ListNode *right){
		ListNode *result = new ListNode(0);
		ListNode *cur = result;
		
		while(left != NULL && right != NULL){
			if(left->val < right->val){
				cur->next = left;
				cur = left;
				left = left->next;
			}
			else{
				cur->next = right;
				cur = right;
				right = right->next;
			}
		}
		if(left != NULL){
			cur->next = left;
		}
		else if(right != NULL){
			cur->next = right;
		}
		else{
		    cur->next = NULL;
		}

		return result->next;
	}
	ListNode *mergeLists(vector<ListNode *> lists, int begin, int end){
		if(begin == end){
			return lists[begin];
		}
		int middle = begin + (begin - end) / 2;
		ListNode *left = mergeLists(lists, begin, middle);
		ListNode *right = mergeLists(lists, middle + 1, end);
		return mergeTwo(left, right);
	}
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int len = lists.size();
        
        if(len <= 0){
            return NULL;
        }
        
        return mergeLists(lists, 0, len - 1);
    }
};