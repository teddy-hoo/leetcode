/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define MIN_INT -2147483648
 
class Solution {
private:
    bool serial(TreeNode *root){
        if(!root){
            return true;
        }
        stack<TreeNode*> s;
        TreeNode* cur = root;
        int pre = MIN_INT;
        bool first = true;
        while(!s.empty() || cur){
            if(cur){
                s.push(cur);
                cur = cur->left;
            }
            else{
                cur = s.top();
                s.pop();
                if(!first && cur->val <= pre){
                    return false;
                }
                first = false;
                pre = cur->val;
                cur = cur->right;
            }
        }
        return true;
    }
public:
    bool isValidBST(TreeNode *root) {
        if(!root){
            return true;
        }
        return serial(root);
    }
};
