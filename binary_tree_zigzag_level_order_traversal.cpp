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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if(!root){
            return result;
        }
        vector<TreeNode*> row;
        row.push_back(root);
        vector<int> level;
        level.push_back(root->val);
        result.push_back(level);
        bool forward = false;
        while(row.size() > 0){
            vector<TreeNode*> tmp;
            level.clear();
            for(int i = row.size() - 1; i >= 0; i--){
                if(forward){
                    if(row[i]->left){
                        tmp.push_back(row[i]->left);
                        level.push_back(row[i]->left->val);
                    }
                    if(row[i]->right){
                        tmp.push_back(row[i]->right);
                        level.push_back(row[i]->right->val);
                    }
                }
                else{
                    if(row[i]->right){
                        tmp.push_back(row[i]->right);
                        level.push_back(row[i]->right->val);
                    }
                    if(row[i]->left){
                        tmp.push_back(row[i]->left);
                        level.push_back(row[i]->left->val);
                    }
                }
            }
            forward = !forward;
            if(level.size() > 0){
                result.push_back(level);
            }
            row = tmp;
        }
        return result;
    }
};
