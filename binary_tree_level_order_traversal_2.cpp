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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        queue<TreeNode *> qu;
        stack<vector<int> > st;
        TreeNode *cur;
        vector<int> row;
        vector<vector<int> > result;
        if(root == NULL)
            return result;
        qu.push(root);
        qu.push(NULL);
        while(!qu.empty()){
            cur = qu.front();
            qu.pop();
            if(cur == NULL){
                st.push(row);
                row.clear();
                if(!qu.empty())
                    qu.push(NULL);
                continue;
            }
            row.push_back(cur->val);
            if(cur->left != NULL)
                qu.push(cur->left);
            if(cur->right != NULL)
                qu.push(cur->right);
        }
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};
