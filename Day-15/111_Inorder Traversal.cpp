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

/************** Morris traversal for InOrder ***********/
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    if(!root)   return ans;
    TreeNode *curr = root;
    while(curr)
    {
        if(curr->left==nullptr){
            ans.push_back(curr->data);
            curr=curr->right;
        } else{
            // check whether left subtree already visited or not
            TreeNode *temp = curr->left;
            while(temp->right && temp->right!=curr) temp=temp->right;
            if(temp->right==nullptr){ // not already visited
                temp->right = curr;
                curr=curr->left;
            } else{ // already visited
                temp->right=nullptr;
                ans.push_back(curr->data);
                curr=curr->right;
            }
        }
    }
    return ans;
}




/************* Iterative *******/
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    if(!root)   return ans;
    stack<TreeNode*>st;
    TreeNode* node = root;
    while(true)
    {
        if(node!=nullptr){
            st.push(node);
            node = node->left;
        } else{
            if(st.empty())  break;
            node = st.top();   st.pop();
            ans.push_back(node->data);
            node = node->right;
        }
    }
    return ans;
}


/************ Recursive ***********/
void solve(TreeNode* root, vector<int>& ans)
{
    if(!root)   return;
    solve(root->left,ans);  
    ans.push_back(root->data);
    solve(root->right,ans);
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    solve(root,ans);
    return ans;
}