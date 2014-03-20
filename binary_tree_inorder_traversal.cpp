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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* cur;
        if(!root)
            return result;
        s.push(root);
        cur = root->left;
        while(!s.empty() || cur){
            while(cur){
                s.push(cur);
                cur = cur->left;
            }
            if(!s.empty()){
                cur = s.top();
                s.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
};
