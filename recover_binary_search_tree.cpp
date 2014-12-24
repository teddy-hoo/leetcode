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
	vector<TreeNode*> findSwappedNode(TreeNode *root){
		stack<TreeNode *> s;
		TreeNode *cur = root;

		TreeNode *preNode = NULL;
		vector<TreeNode*> results;

		while(!s.empty() || cur){
			if(cur){
				s.push(cur);
				cur = cur->left;
			}
			else{
				cur = s.top();
				s.pop();
				if(preNode != NULL && preNode->val > cur->val){
					results.push(results.size() == 0 ? preNode : cur);
				}
				preNode = cur;
				cur = cur->right;
			}
		}
		return results;
	}
public:
    void recoverTree(TreeNode *root) {
        if(!root){
        	return;
        }
        vector<TreeNode *> swappedNodes;

        swappedNodes = findSwappedNode(root);
        if(swappedNodes.size() > 2 || swappedNodes.size() <= 0){
        	return;
        }
       	swappedNodes[0]->val = swappedNodes[1]->val;
    }
};
