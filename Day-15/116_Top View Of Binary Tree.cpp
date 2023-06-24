#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root) {
    vector<int> ans;
    if(!root)   return ans;
    unordered_map<int,int> mp;
    queue<pair<TreeNode<int>*,int>>q;
    q.push({root,0});
    int mini=INT_MAX, maxi=INT_MIN;
    while(!q.empty()){
        int size=q.size();
        while(size--){
            TreeNode<int>* curr=q.front().first;
            int x=q.front().second; mini=min(mini,x);   maxi=max(maxi,x);
            q.pop();
            if(mp.find(x)==mp.end())    mp[x]=curr->val;
            if(curr->left)  q.push({curr->left,x-1});
            if(curr->right)  q.push({curr->right,x+1});
        }
    }
    for(int i=mini; i<=maxi; i++)   ans.push_back(mp[i]);
    return ans;
}