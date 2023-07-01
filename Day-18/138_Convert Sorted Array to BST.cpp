#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int>* solve(vector<int>&arr, int i, int j)
{
    if(i>j) return nullptr;
    int mid = (i+j)>>1;
    TreeNode<int> *root = new TreeNode<int>(arr[mid]);
    root->left = solve(arr,i,mid-1);
    root->right = solve(arr,mid+1,j);
    return root;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    if(n==0)    return nullptr;
    return solve(arr,0,n-1);
}