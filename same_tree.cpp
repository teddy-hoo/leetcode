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
        if((p == NULL) ^ (q == NULL)){
            return false;
        }

        TreeNode *p1 = p;
        TreeNode *p2 = q;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;

        while((!s1.empty() || p1 != NULL) && (!s2.empty() || p2 != NULL)){
            if((p1 == NULL) ^ (p2 == NULL)){
                return false;
            }
            if(p1 != NULL){
                if(p1->val != p2->val){
                    return false;
                }
                s1.push(p1);
                s2.push(p2);
                p1 = p1->left;
                p2 = p2->left;
            }
            else{
                p1 = s1.top();
                s1.pop();
                p2 = s2.top();
                s2.pop();
                p1 = p1->right;
                p2 = p2->right;
            }
        }

        if(s1.empty() ^ s1.empty()){
            return false;
        }

        if((p1 == NULL) ^ (p2 == NULL)){
            return false;
        }

        return true;

    }
};