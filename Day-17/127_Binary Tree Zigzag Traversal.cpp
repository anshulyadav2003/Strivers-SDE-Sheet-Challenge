#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if(!root)   return ans;
    bool lr = true;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> temp;
        while(size--){
            auto curr = q.front();
            q.pop();
            temp.push_back(curr->data);
            if(curr->left)  q.push(curr->left);
            if(curr->right)  q.push(curr->right);
        }
        if(lr==false)   reverse(begin(temp),end(temp));
        for(auto it: temp) ans.push_back(it);
        lr = !lr;
    }
    return ans;
}
