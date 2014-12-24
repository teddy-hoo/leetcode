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
	vector<int> post;

	int findRoot(int target, int beginIn, int len){
		for(int i = 0; i < len; i++){
			if(in[beginIn + i] == target){
				return i;
			}
		}
		return -1;
	}

	TreeNode *buildBinaryTree(int beginIn, int beginPost, int len){
		if(len <= 0){
			return NULL;
		}
		TreeNode *root = new TreeNode(post[beginPost + len - 1]);
		int rootPos = findRoot(post[beginPost + len - 1], beginIn, len);
		if(rootPos == -1){
			return NULL;
		}
		int newLenLeft = rootPos;
		int newLenRight = len - newLenLeft - 1;
		root->left = buildBinaryTree(beginIn, beginPost, newLenLeft);
		root->right = buildBinaryTree(beginIn + rootPos + 1, beginPost + newLenLeft, newLenRight);
		return root;
	}

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
       	if(inorder.size() == 0 ||
    	   postorder.size() == 0 ||
    	   inorder.size() != postorder.size()){
    		return NULL;
    	}

    	in = inorder;
    	post = postorder;

    	return buildBinaryTree(0, 0, in.size());
    }

};