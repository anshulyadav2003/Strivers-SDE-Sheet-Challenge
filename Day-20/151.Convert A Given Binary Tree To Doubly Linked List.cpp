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

pair<BinaryTreeNode<int>*,BinaryTreeNode<int>*> solve(BinaryTreeNode<int>* root)
{
    if(!root)   return {NULL,NULL};
    auto l = solve(root->left);
    auto r = solve(root->right);
    BinaryTreeNode<int> *lh=l.first,    *lt=l.second;
    BinaryTreeNode<int> *rh=r.first,    *rt=r.second;
    if(!lh && !lt && !rh && !rt)  return {root,root};
    if(!lh && !lt){
        root->right = rh;
        rh->left = root;
        return {root,rt};
    }
    if(!rh && !rt){
        lt->right = root;
        root->left = lt;
        return {lh,root};
    }
    lt->right = root;
    root->left = lt;
    root->right = rh;
    rh->left = root;
    return {lh,rt};
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    return solve(root).first;
}