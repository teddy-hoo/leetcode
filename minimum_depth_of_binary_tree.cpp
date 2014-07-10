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
  int minDepth(TreeNode *root) {
    queue<TreeNode*> q;
    TreeNode* pot;
    if(!root){
      return 0;
    }
    TreeNode* flag = new TreeNode(-9999);
    q.push(root);
    q.push(flag);
  }
};
