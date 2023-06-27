#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int solve(TreeNode<int>* root, int x, int y)
{
    if(!root)  return -1; 
    if(root->data==x)   return x;
    if(root->data==y)   return y;

    int l = solve(root->left,x,y);
    int r = solve(root->right,x,y);
    if(l==-1 && r!=-1)  return r;
    if(l!=-1 && r==-1)  return l;
    if(l!=-1 && r!=-1)  return root->data; 
    return -1;
}


int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    if(!root)   return -1;
	return solve(root,x,y);
}