#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode<int> *root) {
    if(!root || (!root->left && !root->right))  return;

    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        BinaryTreeNode<int>* a=nullptr;
        while(size--){
            BinaryTreeNode<int>* curr = q.front();
            q.pop();
            if(a==nullptr)  a=curr;
            else{
                a->next = curr;
                a=curr;
            }

            if(curr->left)  q.push(curr->left);
            if(curr->right)  q.push(curr->right);
        }
    }

}