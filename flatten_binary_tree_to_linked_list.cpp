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
    void genQueue(TreeNode *root, queue<TreeNode*> &q){
        stack<TreeNode*> s;
        TreeNode *curNode = root;

        while(!s.empty() || curNode != NULL){
            while(curNode != NULL){
                q.push(curNode);
                s.push(curNode);
                curNode = curNode->left;
            }
            if(!s.empty()){
                curNode = s.top();
                s.pop();
                curNode = curNode->right;
            }
        }
    }
    void buildNewTree(queue<TreeNode*> q){
        TreeNode *curNode;
        curNode = q.front();
        curNode->left = NULL;
        curNode->right = NULL;
        q.pop();
        while(!q.empty()){
            curNode->right = q.front();
            q.pop();
            curNode = curNode->right;
            curNode->left = NULL;
            curNode->right = NULL;
        }
    }
public:
    void flatten(TreeNode *root) {
        if(root == NULL){
        	return;
        }

        queue<TreeNode*> q;

        genQueue(root, q);
        buildNewTree(q);        

    }
};