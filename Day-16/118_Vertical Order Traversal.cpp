#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    if(!root)   return  ans;
    unordered_map<int,vector<int>> mp;
    queue<pair<TreeNode<int>*,int>> q;
    q.push({root,0});
    int mini=INT_MAX, maxi=INT_MIN;
    while(!q.empty())
    {
        TreeNode<int> *curr=q.front().first;
        int x = q.front().second;
        q.pop();
        mini = min(mini,x); maxi=max(maxi,x);
        mp[x].push_back(curr->data);
        if(curr->left)  q.push({curr->left,x-1});
        if(curr->right)  q.push({curr->right,x+1});
    }

    for(int i=mini; i<=maxi; i++){
        auto v = mp[i];
        for(auto it: v) ans.push_back(it);
    }
    return ans;
}