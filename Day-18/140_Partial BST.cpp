#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
bool solve(BinaryTreeNode<int> *root, int mini, int maxi) {
    if(!root)   return true;
    int val = root->data;
    if(val<mini || val>maxi)    return false;
    bool op1 = solve(root->left, mini, val);
    bool op2 = solve(root->right, val, maxi);
    return op1&&op2;
}

bool validateBST(BinaryTreeNode<int> *root) {
    if(!root)   return true;
    return solve(root,INT_MIN,INT_MAX);
}