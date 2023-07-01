#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int prevP=INT_MIN, prevS=INT_MAX;
    while(root && root->data != key){
        int val = root->data;
        if(val<key) prevP = max(prevP, val);
        if(val>key) prevS = min(prevS, val);

        if(val<key) root=root->right;
        else        root=root->left;
    }
    if(!root)   return {-1,-1};

    // pred
    BinaryTreeNode<int> *pred = root->left;
    while(pred && pred->right)  pred=pred->right;
    // succ
    BinaryTreeNode<int> *succ = root->right;
    while(succ && succ->left)  succ=succ->left;

    pair<int,int> ans = {prevP==INT_MIN ? -1:prevP, prevS==INT_MAX ? -1:prevS};
    if(pred)    ans.first = pred->data;
    if(succ)    ans.second = succ->data;
    return ans;
}
