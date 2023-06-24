#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> * root){
    vector<int> ans;
    if(!root)   return ans;
    unordered_map<int,int> mp;
    queue<pair<BinaryTreeNode<int>*,int>>q;
    q.push({root,0});
    int mini=INT_MAX, maxi=INT_MIN;
    while(!q.empty()){
        int size=q.size();
        while(size--){
            BinaryTreeNode<int>* curr=q.front().first;
            int x=q.front().second; mini=min(mini,x);   maxi=max(maxi,x);
            q.pop();
            mp[x]=curr->data;
            if(curr->left)  q.push({curr->left,x-1});
            if(curr->right)  q.push({curr->right,x+1});
        }
    }
    for(int i=mini; i<=maxi; i++)   ans.push_back(mp[i]);
    return ans;
}
