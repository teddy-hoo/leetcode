/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
#define LN ListNode*
#define HEAP heap.begin(),heap.end()
#define PB push_back
#define INF 1000000

struct node
{
	int val;
	LN from;
	
	node(ListNode* n)
	{
		if ( n==NULL )
		{
			val=INF;
		}
		else
		{
			val=n->val;
		}			
		from=n;
	}
	bool operator<(const node& other)const
	{
		return val<other.val;
	}
	bool operator>(const node& other)const
	{
		return val>other.val;
	}
};
    
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (lists.empty()) return NULL;
	int n= lists.size();
	vector<node> heap;
	heap.reserve(n);
	for( int i=0;i<n;i++)
		heap.PB(node(lists[i]));
	make_heap(HEAP,greater<node>());
	LN head= new ListNode(0);
	LN pL = head;
	pop_heap(HEAP,greater<node>());
	node small=heap.back();
	heap.pop_back();
	while(small.val!=INF)
	{
		LN next=small.from->next;
		pL->next=small.from;
		small.from->next=NULL;
		pL=pL->next;

		heap.PB(node(next));
		push_heap(HEAP,greater<node>());
		pop_heap(HEAP,greater<node>());
		small=heap.back();
		heap.pop_back();
	}

	LN ret=head->next;
	delete head;
	return ret;    }
};
