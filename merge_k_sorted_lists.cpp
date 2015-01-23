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
	int buildHeap(vector<ListNode *> &heap, vector<ListNode *> lists){
		int heapSize = 0;
		for(int i = 0; i < lists.size(); i++){
			if(lists[i] == NULL){
				continue;
			}
			heapSize++;
			insertHeap(heap, lists[i], heapSize);
		}
		return heapSize;
	}
	void insertHeap(vector<ListNode *> &heap, ListNode *newNode, int heapSize){
		heap.push_back(newNode);
		int cur = heapSize - 1;
		int parent = (cur - 1) / 2;
		while(cur >= 1){
			if(heap[parent]->val > heap[cur]->val){
				ListNode *tmp = heap[cur];
				heap[cur] = heap[parent];
				heap[parent] = tmp;
				cur = parent;
				parent = (cur - 1) / 2;
			}
			else{
				break;
			}
		}
	}
	void adjustHeap(vector<ListNode *> &heap, int heapSize){
		int cur = 0;
		while(cur < heapSize){
			int left = cur * 2 + 1;
			int right = cur * 2 + 2;
			if(right < heapSize){
				if(heap[left]->val < heap[right]->val){
					if(heap[left]->val < heap[cur]->val){
						ListNode *tmp = heap[cur];
						heap[cur] = heap[left];
						heap[left] = tmp;
						cur = left;
					}
					else if(heap[right]->val < heap[cur]->val){
						ListNode *tmp = heap[cur];
						heap[cur] = heap[right];
						heap[right] = tmp;
						cur = right;
					}
					else{
						break;
					}
				}
				else{
					if(heap[right]->val < heap[cur]->val){
						ListNode *tmp = heap[cur];
						heap[cur] = heap[right];
						heap[right] = tmp;
						cur = right;
					}
					else if(heap[left]->val < heap[cur]->val){
						ListNode *tmp = heap[cur];
						heap[cur] = heap[left];
						heap[left] = tmp;
						cur = left;
					}
					else{
						break;
					}
				}
			}
			else if(left < heapSize){
				if(heap[left]->val < heap[cur]->val){
					ListNode *tmp = heap[cur];
					heap[cur] = heap[left];
					heap[left] = tmp;
					cur = left;
				}
				else{
					break;
				}
			}
			else{
				break;
			}
		}
	}
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {

        ListNode *newList = new ListNode(0);
        int len = lists.size();

        if(len <= 0){
        	return newList->next;
        }

        vector<ListNode *> heap;
        int heapSize = buildHeap(heap, lists);

        ListNode *n = newList;
        while(heapSize > 0){
        	ListNode *cur = heap[0];
        	n->next = cur;
        	n = cur;
        	if(cur->next == NULL){
        		if(heapSize == 1){
        			break;
        		}
        		else{
        			heap[0] = heap[heapSize - 1];
        			heap[heapSize - 1] = NULL;
        			heapSize--;
        		}
        	}
        	else{
        		heap[0] = cur->next;
        	}
        	adjustHeap(heap, heapSize);
        }
        
        n->next = NULL;

        return newList->next;
    }
};