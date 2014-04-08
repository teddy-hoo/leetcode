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
    bool isBalanced(TreeNode *root) {
        if(!root)
            return true;
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        if(left - right > 1 || left - right < -1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int getDepth(TreeNode* root){
        if(!root)
            return 0;
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        return 1 + (right > left? right : left);
    }
};
