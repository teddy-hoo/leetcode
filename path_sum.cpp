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
    bool hasPathSum(TreeNode *root, int sum) {
        if(root == NULL)
            return false;
        int tmpsum = 0;
	    map<TreeNode*, int> m;
	    TreeNode* cur;
	    stack<TreeNode*> st;
	    tmpsum += root->val;
	    st.push(root);
	    m.insert(pair<TreeNode*, bool>(root, 0));
	    while(!st.empty()){
		    cur = st.top();
		    if(cur->left != NULL && m[cur] == 0){
			    st.push(cur->left);
			    tmpsum += cur->left->val;
			    m[cur] = 1;
			    m.insert(pair<TreeNode*, bool>(cur->left, 0));
			    continue;
		    }
		    if(cur->right != NULL){
			    if(m[cur] == 2){
				    st.pop();
				    tmpsum -= cur->val;
				    continue;
			    }
			    st.push(cur->right);
			    tmpsum += cur->right->val;
			    m[cur] = 2;
			    m.insert(pair<TreeNode*, bool>(cur->right, 0));
			    continue;
		    }
		    if (m[cur] == 1)
		    {
			    st.pop();
			    tmpsum -= cur->val;
			    continue;
		    }
		
		    if(sum == tmpsum)
		        return true;
		    tmpsum -= cur->val;
		    st.pop();
	    }
	    return false;
    }
};
