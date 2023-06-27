#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#define lli long long int
lli ans=-1;
lli solve(TreeNode<int>* root)
{
    if(!root)   return -1;
    
    lli l = solve(root->left);
    lli r = solve(root->right);
    if(l!=-1 && r!=-1)  ans=max(ans, l+r+root->val);

    if(l==-1 && r==-1)  return root->val;
    return root->val + max(l,r);
}


long long int findMaxSumPath(TreeNode<int> *root)
{
    if(!root || (!root->left && !root->right))  return -1;   
    ans = -1;
    solve(root);
    return ans;
}