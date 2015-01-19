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
    bool sameTreeRecusion(TreeNode *p, TreeNode *q){
        if(p ^ q){
            return false;
        }
        if(!p){
            return true;
        }
        if(p->val != q->val){
            return false;
        }
        return sameTreeRecusion(p->left, q->left) && 
               sameTreeRecusion(p->right, q->right);
    }
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if((p == NULL) ^ (q == NULL)){
            return false;
        }

        return sameTreeRecusion(p, q);

    }
};