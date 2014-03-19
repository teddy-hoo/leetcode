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
    int maxDepth(TreeNode *root) {
        queue<TreeNode*> q;
        TreeNode* flag = new TreeNode(-99999);
        TreeNode* cur;
        if(root == NULL)
            return 0;
        int floor = 0;
        q.push(root);
        q.push(flag);
        while(!q.empty()){
            cur = q.front();
            q.pop();
            if(cur->val == flag->val){
                floor++;
                if(!q.empty())
                    q.push(flag);
                continue;
            }
            if(cur->left != NULL)
                q.push(cur->left);
            if(cur->right != NULL)
                q.push(cur->right);
        }
        return floor;
    }
};
