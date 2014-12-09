/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int getLength(ListNode * head){
        int len = 0;
        ListNode *p = head;
        while(p != NULL){
            p = p->next;
            len++;
        }
        return len;
    }
    TreeNode *buildTree(ListNode *&head, int begin, int end){
        if(begin > end){
            return NULL;
        }
        int mid = (begin + end) / 2;
        TreeNode *left = buildTree(head, begin, mid - 1);
        TreeNode *root = new TreeNode(head->val);
        head = head->next;
        TreeNode *right = buildTree(head, mid + 1, end);
        root->left = left;
        root->right = right;
        return root;
    }
public:
    TreeNode *sortedListToBST(ListNode *head){
	    int len = getLength(head);
        return buildTree(head, 0, len-1);
    }
};
