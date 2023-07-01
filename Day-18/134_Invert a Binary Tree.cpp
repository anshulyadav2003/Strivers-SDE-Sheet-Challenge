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
void findPath(TreeNode<int>* root, TreeNode<int>* leaf, stack<TreeNode<int>*> &st)
{
    if(!root)   return;
    st.push(root);
    if(root->data==leaf->data)  return;
    findPath(root->left, leaf, st);
    if(!st.empty() && st.top()->data==leaf->data)   return;
    findPath(root->right, leaf, st);
    if(!st.empty() && st.top()->data==leaf->data)   return;
    st.pop();
}


TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
    if(!root)   return root;
    stack<TreeNode<int>*> st;
    findPath(root,leaf,st); // find path from 'root' to given 'leaf' and store it into stack
    
    TreeNode<int> *ans = st.top(); 
    // invert now
    while(st.size()>1)
    {
        TreeNode<int> *root = st.top(); st.pop();
        TreeNode<int> *par = st.top();
        if(par->left==root){
            root->left = par;
            par->left = nullptr;
        } else if(par->right==root){
            root->left = par;
            par->right = par->left;
            par->left = nullptr;
        }
    }
    return ans;
}
