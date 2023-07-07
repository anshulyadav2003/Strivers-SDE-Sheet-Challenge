#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
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
vector<int> solve(TreeNode<int>* root, int &ans, bool isleft) {
    int mini=INT_MAX,   maxi = INT_MIN;
    if(!root)   return {mini,maxi,0};
    
    vector<int> l = solve(root->left,ans,true);
    vector<int> r = solve(root->right,ans,false);
    int cnt = l[2]+r[2]+1;
    int lmin=l[0],  lmax=l[1];
    int rmin=r[0],  rmax=r[1];
    bool cond = (root->data > lmax && root->data < rmin);
    if(cond)    ans=max(ans, cnt);

    mini = !cond ? INT_MIN : min({lmin, rmin, root->data});
    maxi = !cond ? INT_MAX : max({lmax, rmax, root->data});
    return {mini,maxi,cnt};
}

int largestBST(TreeNode<int>* root) 
{
    if(!root)   return 0;
    int ans=1;
    solve(root,ans,true);
    return ans;
}
