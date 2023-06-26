#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if(!root)   return ans;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(q.size()>0){
        auto curr=q.front();  q.pop();
        ans.push_back(curr->val);
        if(curr->left)  q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    return ans;
}