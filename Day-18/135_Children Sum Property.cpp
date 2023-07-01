#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

int solve(BinaryTreeNode<int>* root, int val)
{
    if(!root)   return 0;
    int l = solve(root->left, max(val,root->data));
    int r = solve(root->right, max(val,root->data));
    if(!root->left && !root->right){
        root->data = max(val,root->data);
        return root->data;
    }
    root->data = l+r;
    return root->data;
}


void changeTree(BinaryTreeNode<int>* root) {
    if(!root)   return;
    solve(root, root->data);
}  