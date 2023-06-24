#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/


/************** Morris traversal for PreOrder ***********/
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    if(!root)   return ans;
    TreeNode *curr=root;
    while(curr)
    {
        if(curr->left==nullptr){
            ans.push_back(curr->data);
            curr=curr->right;
        } else{
            TreeNode *temp=curr->left;
            while(temp->right && temp->right!=curr) temp=temp->right;
            if(temp->right==nullptr){
                temp->right=curr;
                ans.push_back(curr->data);
                curr=curr->left;
            } else{
                temp->right=nullptr;
                curr=curr->right;
            }
        }
    }
    return ans;
}



vector<int> getPreOrderTraversal(TreeNode *root)
{
    /********* iterative **********/
    vector<int> ans;
    if(!root)   return ans;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty())
    {
        auto curr = st.top();    st.pop();
        ans.push_back(curr->data);
        if(curr->right) st.push(curr->right); 
        if(curr->left) st.push(curr->left); 
    }
    return ans;
}