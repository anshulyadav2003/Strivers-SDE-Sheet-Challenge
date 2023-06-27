#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void leftNodes(TreeNode<int>* root, vector<int>& ans)
{
    if(!root)   return;
    if(!root->left && !root->right) return;

    ans.push_back(root->data);
    if(root->left)  leftNodes(root->left,ans);
    else    leftNodes(root->right,ans);
}

void rightNodes(TreeNode<int>* root, vector<int>& ans)
{
    if(!root)   return;
    if(!root->left && !root->right) return;

    if(root->right) rightNodes(root->right,ans);
    else    rightNodes(root->left,ans);
    ans.push_back(root->data);
}

void leafNodes(TreeNode<int>* root, vector<int>& ans)
{
    if(!root)   return;
    if(!root->left && !root->right){
        ans.push_back(root->data);
        return;
    }
    
    leafNodes(root->left, ans);
    leafNodes(root->right, ans);
}


vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if(!root)   return ans;
    ans.push_back(root->data); // push root node
    if(!root->left && !root->right) return ans;

    // extract left side nodes
    leftNodes(root->left,ans);
    // extract leaf nodes
    leafNodes(root,ans);
    // extract right side nodes
    rightNodes(root->right,ans);

    return ans; 
}