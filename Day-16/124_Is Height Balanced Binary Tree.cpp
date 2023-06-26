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
bool isBalance = true;

int solve(BinaryTreeNode<int>* root)
{
    if(!root)   return 0;
    int l = solve(root->left);
    if(l==INT_MIN)  return INT_MIN;
    int r = solve(root->right);
    if(r==INT_MIN)  return INT_MIN;
    if(abs(l-r)>1){
        isBalance = false;
        return INT_MIN;
    }
    return 1+max(l,r);
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    isBalance=true;
    solve(root);
    return isBalance;
}