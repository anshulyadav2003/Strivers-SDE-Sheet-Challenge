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
vector<int> getPostOrderTraversal(TreeNode *root)
{
    /********* iterative **********/
    vector<int> ans;
    if(!root)   return ans;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty())
    {
        auto curr = st.top();   st.pop();
        ans.push_back(curr->data);
        if(curr->left)  st.push(curr->left);
        if(curr->right)  st.push(curr->right);
    }
    reverse(begin(ans),end(ans));
    return ans;
}