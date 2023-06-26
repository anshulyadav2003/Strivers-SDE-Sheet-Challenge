#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/
void solve(TreeNode<int> *root, int x, vector<int> curr, vector<int> &ans){
	if(!root)	return;
	curr.push_back(root->data);
	if(root->data==x){
		ans=curr;	return;
	}
	solve(root->left,x,curr,ans);
	solve(root->right,x,curr,ans);
	curr.pop_back();
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> ans;
    vector<int> curr;
	solve(root,x,curr,ans);
	return ans;
}
