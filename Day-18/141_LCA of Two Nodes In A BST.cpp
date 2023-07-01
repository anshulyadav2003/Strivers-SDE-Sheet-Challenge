#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* a, TreeNode<int>* b)
{
    if(!root)   return root;
    
    if(root->data > a->data && root->data > b->data)    
        return LCAinaBST(root->left, a, b);
    else if(root->data < a->data && root->data < b->data)    
        return LCAinaBST(root->right, a, b);
    else    
        return root;
}
