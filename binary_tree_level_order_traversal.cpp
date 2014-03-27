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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<int> row;
        vector<vector<int> > result;
        queue<TreeNode*> q;
        TreeNode* flag = new TreeNode(-99999);
        TreeNode* cur;
        if(!root)
            return result;
        q.push(root);
        q.push(flag);
        while(!q.empty()){
            cur = q.front();
            q.pop();
            if(cur->val == flag->val){
                result.push_back(row);
                row.clear();
                if(q.empty())
                    return result;
                q.push(flag);
            }
            else{
                row.push_back(cur->val);
            }
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
    }
};
