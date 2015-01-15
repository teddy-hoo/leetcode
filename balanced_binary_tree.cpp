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
    bool calHeight(TreeNode *root, int &height){
        if(root == NULL){
            height = 0;
            return true;
        }

        int leftHeight = 0;
        if(!calHeight(root->left, leftHeight)){
            return false;
        }
        int rightHeight = 0;
        if(!calHeight(root->right, rightHeight)){
            return false;
        }

        if(abs(leftHeight - rightHeight) > 1){
            return false;
        }

        height = leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;

        return true;

    }
public:
    bool isBalanced(TreeNode *root) {
        
        if(root == NULL){
            return true;
        }

        int height = 0;
        return calHeight(root, height);

    }
};
