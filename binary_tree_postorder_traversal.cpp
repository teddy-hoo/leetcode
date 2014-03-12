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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> pos;
        postral(root, pos);
        return pos;
    }
    void postral(TreeNode *root, vector<int> &pos){
        if(root == NULL)
            return;
        postral(root->left, pos);
        postral(root->right, pos);
        pos.push_back(root->val);
    }
};
