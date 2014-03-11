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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        queue<TreeNode*> t1;
        queue<TreeNode*> t2;
        TreeNode* p1;
        TreeNode* p2;
        if(p != NULL)
            t1.push(p);
        if(q != NULL)
            t2.push(q);
        while(!t1.empty() && !t2.empty()){
            p1 = t1.front();
            t1.pop();
            p2 = t2.front();
            t2.pop();
            if(p1->val != p2->val || (p1->left != NULL && p2->left == NULL) || (p1->left == NULL && p2->left != NULL)
            || (p1->right != NULL && p2->right == NULL) || (p1->right == NULL && p2->right != NULL))
                return false;
            if(p1->left != NULL){
                t2.push(p2->left);
                t1.push(p1->left);
            }
            if(p1->right != NULL){
                t1.push(p1->right);
                t2.push(p2->right);
            }
        }
        if(!t1.empty() || !t2.empty())
            return false;
        else
            return true;
    }
};
