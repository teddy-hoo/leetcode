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
	vector<int> in;
	vector<int> pre;

	int findRoot(int target, int beginIn, int len){
		for(int i = 0; i < len; i++){
			if(in[beginIn + i] == target){
				return i;
			}
		}
		return -1;
	}

	TreeNode *buildBinaryTree(int beginIn, int beginPre, int len){
		if(len <= 0){
			return NULL;
		}
		int rootValue = pre[beginPre];
		TreeNode *root = new TreeNode(rootValue);
		int rootPos = findRoot(rootValue, beginIn, len);
		if(rootPos == -1){
			return NULL;
		}
		int newLenLeft = rootPos;
		int newLenRight = len - newLenLeft - 1;
		root->left = buildBinaryTree(beginIn, beginPre + 1, newLenLeft);
		root->right = buildBinaryTree(beginIn + newLenLeft + 1, beginIn + newLenLeft + 1, newLenRight);
		return root;
	}

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(inorder.size() == 0 ||
    	   preorder.size() == 0 ||
    	   inorder.size() != preorder.size()){
    		return NULL;
    	}

    	in = inorder;
    	pre = preorder;

    	return buildBinaryTree(0, 0, in.size());
    }
};