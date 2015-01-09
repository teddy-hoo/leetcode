/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    vector<TreeNode *> list;
    int len;
    int cur;
    void convertTreetoList(TreeNode *root){
        stack<TreeNode *> s;
        TreeNode *cur = root;
        while(!s.empty() || cur != NULL){
            if(cur != NULL){
                s.push(cur);
                cur = cur->left;
            }
            else{
                cur = s.top();
                s.pop();
                list.push_back(cur);
                cur = cur->right;
            }
        }
    }
public:
    BSTIterator(TreeNode *root) {
        convertTreetoList(root);
        len = list.size();
        cur = 0;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur < len;
    }

    /** @return the next smallest number */
    int next() {
        return list[cur++]->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */