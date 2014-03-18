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
    int sumNumbers(TreeNode *root) {
        if(root == NULL)
            return 0;
        map<TreeNode*, int> m;
        TreeNode* cur;
        stack<TreeNode*> st;
        int sum = 0;
        int rawsum = 0;
        rawsum = rawsum * 10 + root->val;
        st.push(root);
        m.insert(pair<TreeNode*, bool>(root, 0));
        while(!st.empty()){
		cur = st.top();
		if(cur->left != NULL && m[cur] == 0){
			st.push(cur->left);
			rawsum = rawsum * 10 + cur->left->val;
			m[cur] = 1;
			m.insert(pair<TreeNode*, bool>(cur->left, 0));
			continue;
		}
		if(cur->right != NULL){
			if(m[cur] == 2){
				st.pop();
				rawsum = rawsum / 10;
				continue;
			}
			st.push(cur->right);
			rawsum = rawsum * 10 + cur->right->val;
			m[cur] = 2;
			m.insert(pair<TreeNode*, bool>(cur->right, 0));
			continue;
		}
		if (m[cur] == 1)
		{
			st.pop();
			rawsum = rawsum / 10;
			continue;
		}
		sum += rawsum;
		rawsum = rawsum / 10;
		st.pop();
        }
        return sum;
    }
};
