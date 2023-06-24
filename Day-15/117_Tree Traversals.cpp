#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/

/********* Iterative (Using stack)***********/
void solve(BinaryTreeNode<int> *root, vector<int>& ino,vector<int>& pre,vector<int>& post)
{
    if(!root)   return;
    stack<pair<BinaryTreeNode<int>*,int>> st;
    st.push({root,1});
    while(!st.empty())
    {
        BinaryTreeNode<int>* curr=st.top().first; 
        int num=st.top().second;
        st.pop();
        if(num==1){ // first visit: push updated curr and also push left child
            pre.push_back(curr->data);
            st.push({curr,num+1});
            if(curr->left)  st.push({curr->left,1});
        } else if(num==2){ // second visit: push updated curr and also push right child
            ino.push_back(curr->data);
            st.push({curr,num+1});
            if(curr->right) st.push({curr->right,1});
        } else if(num==3){ // third visit: no push into stack, just let it go
            post.push_back(curr->data);
        }
    }
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<int> ino,pre,post;
    solve(root,ino,pre,post);
    return {ino,pre,post};
}



/********* Recursive *************/
void solve(BinaryTreeNode<int> *root, vector<int>& ino,vector<int>& pre,vector<int>& post)
{
    if(!root)   return;
    pre.push_back(root->data);
    solve(root->left,ino,pre,post);
    ino.push_back(root->data);
    solve(root->right,ino,pre,post);
    post.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<int> ino,pre,post;
    solve(root,ino,pre,post);
    return {ino,pre,post};
}