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
public:
    void flatten(TreeNode *root) {
        if(root == NULL){
        	return;
        }
        stack<TreeNode*> stk;
        TreeNode *curNode;
        TreeNode *newList = new TreeNode(0);
        TreeNode *pList = newList;
        TreeNode *newNode;

        curNode = root;
        while(!stk.empty() || curNode != NULL){
        	while(curNode != NULL){
        		newNode = new TreeNode(curNode->val);
        		pList->right = newNode;
        		pList = pList->right;
        		stk.push(curNode);
        		curNode = curNode->left;
        	}
        	if(!stk.empty()){
        		curNode = stk.top();
        		stk.pop();
        		curNode = curNode->right;
        	}
        }
        *root = *(newList->right);
    }
};