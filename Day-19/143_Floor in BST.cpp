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

int floorInBST(TreeNode<int> *root, int x)
{
    if(!root)   return -1;
    int ans = -1;
    while(root){
        int num = root->val;
        if(num==x)  return x;
        if(num<=x)  ans = max(ans,num);

        if(num < x) root = root->right;
        else    root = root->left;
    }
    return ans;
}