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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        if(root == NULL)
            return result;
        vector<int> path;
        int tmpsum = 0;
	    map<TreeNode*, int> m;
	    TreeNode* cur;
	    stack<TreeNode*> st;
	    tmpsum += root->val;
	    st.push(root);
	    path.push_back(root->val);
	    m.insert(pair<TreeNode*, bool>(root, 0));
	    while(!st.empty()){
		    cur = st.top();
		    if(cur->left != NULL && m[cur] == 0){
			    st.push(cur->left);
			    tmpsum += cur->left->val;
			    path.push_back(cur->left->val);
			    m[cur] = 1;
			    m.insert(pair<TreeNode*, bool>(cur->left, 0));
			    continue;
		    }
		    if(cur->right != NULL){
			    if(m[cur] == 2){
				    st.pop();
				    tmpsum -= cur->val;
				    path.pop_back();
				    continue;
			    }
			    st.push(cur->right);
			    tmpsum += cur->right->val;
			    path.push_back(cur->right->val);
			    m[cur] = 2;
			    m.insert(pair<TreeNode*, bool>(cur->right, 0));
			    continue;
		    }
		    if (m[cur] == 1)
		    {
			    st.pop();
			    tmpsum -= cur->val;
			    path.pop_back();
			    continue;
		    }

		    if(sum == tmpsum)
		        result.push_back(path);
		    tmpsum -= cur->val;
		    path.pop_back();
		    st.pop();
	    }
    }
};
