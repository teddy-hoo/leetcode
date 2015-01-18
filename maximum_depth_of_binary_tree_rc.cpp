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
    void calDepth(TreeNode *root, int level, int &max){
        
        if(root == NULL){
            max = max > level ? max : level;
            return;
        }
        
        level++;
        
        calDepth(root->left, level, max);
        calDepth(root->right, level, max);
        
    }
public:
    int maxDepth(TreeNode *root) {
        if(root == NULL){
            return 0;
        }
        
        int max = 0;
        calDepth(root, 0, max);
        
        return max;
    }
};