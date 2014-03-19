/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> q;
        TreeLinkNode* cur1;
        TreeLinkNode* cur2;
        TreeLinkNode* flag = new TreeLinkNode(-99999);
        if(!root)
            return;
        q.push(root);
        q.push(flag);
        while(!q.empty()){
            cur1 = q.front();
            q.pop();
            cur2 = q.front();
            if(cur1 == flag){
                if(q.empty())
                    return;
                q.push(flag);
                continue;
            }
            if(cur2 != flag){
                cur1->next = cur2;
            }
            if(cur1->left)
                q.push(cur1->left);
            if(cur1->right)
                q.push(cur1->right);
        }
    }
};
