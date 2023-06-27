#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

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

/********************** O(1) space ************/
pair<TreeNode<int>*,TreeNode<int>*> solve(TreeNode<int>* root)
{
    if(!root)   return {NULL, NULL};
    auto l = solve(root->left);
    auto r = solve(root->right);
    TreeNode<int> *lh=l.first, *lt=l.second;
    TreeNode<int> *rh=r.first, *rt=r.second;
    if(!lh && !rh)  return {root,root};
    else if(!lh)    return {root,rt};
    else if(!rh){
        root->right = lh;
        root->left = NULL;
        return {root,lt};
    }
    TreeNode<int>* temp = root->right;
    root->right = root->left;       root->left=NULL;
    lt->right = temp;
    return {root,rt};
}

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    if(!root || (!root->left && !root->right))   return root;
    solve(root);
    return root;
}


/***********************  O(N) space *************/
TreeNode<int> *head;
void solve(TreeNode<int> *root){
    if(!root)   return;
    TreeNode<int> *tmp = new TreeNode<int>(root->data);
    head->right=tmp;    head=head->right;
    solve(root->left);
    solve(root->right);
}

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *dummy = new TreeNode<int>(-1);
    head=dummy;
    solve(root);
    return dummy->right;
}