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

int KthLargestNumber(TreeNode<int>* root, int &k) 
{
    if(!root)   return -1;
    int r = KthLargestNumber(root->right,k);
    if(r!=-1)   return r;
    
    k--;
    if(k==0)    return root->data;
    return KthLargestNumber(root->left,k);
}
