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
    bool isSymmetric(TreeNode *root) {
        TreeNode* stop = new TreeNode(-9999999);
        vector<TreeNode*> qleft;
        vector<TreeNode*> qright;
        if(!root || (root->left == NULL && root->right == NULL))
            return true;
        if(root->left != NULL){
            qleft.push_back(root->left);
            int indexleft = 0;
            while(indexleft < qleft.size()){
                if(qleft[indexleft]->left != NULL)
                    qleft.push_back(qleft[indexleft]->left);
                else if(qleft[indexleft]->val != stop->val)
                    qleft.push_back(stop);
                if(qleft[indexleft]->right != NULL)
                    qleft.push_back(qleft[indexleft]->right);
                else if(qleft[indexleft]->val != stop->val)
                    qleft.push_back(stop);
                indexleft++;
            }
        }
        if(root->right != NULL){
            qright.push_back(root->right);
            int indexright = 0;
            while(indexright < qright.size()){
                if(qright[indexright]->right != NULL)
                    qright.push_back(qright[indexright]->right);
                else if(qright[indexright]->val != stop->val)
                    qright.push_back(stop);
                if(qright[indexright]->left != NULL)
                    qright.push_back(qright[indexright]->left);
                else if(qright[indexright]->val != stop->val)
                    qright.push_back(stop);
                indexright++;
            }
        }
        int index;
        for(index = 0; index < qleft.size(); index++)
            if(index >= qright.size() || qleft[index]->val != qright[index]->val)
                return false;
        if(index != qright.size())
            return false;
        return true;
    }
};
