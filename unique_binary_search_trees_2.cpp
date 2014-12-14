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
    vector<TreeNode*> make(int start , int end) {
        vector<TreeNode*>result;
        
        if(start > end) {
            result.push_back(NULL);
            return result;
        }
        
        for(int i = start ; i <= end ; ++i) {
            auto leftsub = make(start , i - 1);
            auto rightsub = make(i + 1 , end);
            for(auto left : leftsub) {
                for(auto right : rightsub) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.a(root);
                }
            }
        }
        return result;
    }
public:
    vector<TreeNode *> generateTrees(int n) {
        return make(1 , n);
    }
};
