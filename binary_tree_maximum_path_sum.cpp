/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define INVALID_MIN -10000
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
    	if ( !root ) 
			return 0;
		int sum=0,path=0;
		solve(root,sum,path);
		return sum;
    }
	void solve(TreeNode* root,int& sum,int& path)
	{
		if ( !root )
		{
			sum=path=INVALID_MIN;
			return;
		}
		int lsum=0,lpath=0;
		solve(root->left,lsum,lpath);
		int rsum=0,rpath=0;
		solve(root->right,rsum,rpath);

		path=max(root->val,max(lpath,rpath)+root->val);
		sum=max(max(lsum,rsum),lpath+rpath+root->val);
		sum=max(sum,path);
	}
};
