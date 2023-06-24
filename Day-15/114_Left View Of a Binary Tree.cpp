#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include <queue>
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    if(!root)   return ans;
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        ans.push_back(q.front()->data);
        while(size--){
            auto curr = q.front();  q.pop();
            if(curr->left)  q.push(curr->left);
            if(curr->right)  q.push(curr->right);
        }
    }
    return ans;
}






