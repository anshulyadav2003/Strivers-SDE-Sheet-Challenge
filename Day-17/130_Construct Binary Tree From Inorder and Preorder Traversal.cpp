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
unordered_map<int,int> mp;
TreeNode<int>* solve(int li, int ri, vector<int> &ino, int lp, int rp, vector<int> &pre, int n)
{
    if(li>ri || lp>rp)  return nullptr;

    TreeNode<int>* root = new TreeNode<int>(pre[lp]);
    int rootIdx_inorder = mp[root->data];
    int x = rootIdx_inorder - li;

    root->left = solve(li,rootIdx_inorder-1,ino, lp+1,lp+x,pre,n);
    root->right = solve(rootIdx_inorder+1,ri,ino, lp+x+1,rp,pre,n);
    return root;
}



TreeNode<int> *buildBinaryTree(vector<int> &ino, vector<int> &pre)
{
    if(ino.size()!=pre.size())  return NULL;
	int n=ino.size();
    if(n==0)    return NULL;
    mp.clear();
    for(int i=0; i<n; i++)  mp[ino[i]]=i;
    return solve(0,n-1,ino,0,n-1,pre,n);

}