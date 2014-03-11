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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(num.size() < 0)
            return 0;
        TreeNode* root = buildtree(num, 0, num.size() - 1);
        return root;
    }

    TreeNode* buildtree(vector<int> num, int beg, int end){
        if(beg > end)
        return NULL;
        if(beg == end){;
            return new TreeNode(num[beg]);
        }
        int mid = (beg + end) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = buildtree(num, beg, mid - 1);
        root->right = buildtree(num, mid + 1, end);
        return root;
    }

};
