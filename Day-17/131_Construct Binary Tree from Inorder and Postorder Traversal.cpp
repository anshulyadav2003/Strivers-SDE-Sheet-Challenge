/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
#include <unordered_map>

unordered_map<int,int> mp;
TreeNode<int>* solve(int li, int ri, vector<int> &ino, int lp, int rp, vector<int> &post, int n)
{
    if(li>ri || lp>rp)  return nullptr;

    TreeNode<int>* root = new TreeNode<int>(post[rp]);
    int rootIdx_inorder = mp[root->data];
    int x = ri - rootIdx_inorder;

    root->left = solve(li,rootIdx_inorder-1,ino, lp,rp-x-1,post,n);
    root->right = solve(rootIdx_inorder+1,ri,ino, rp-x,rp-1,post,n);
    return root;
}


TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& post, vector<int>& ino) 
{
     if(ino.size()!=post.size())  return NULL;
     int n=ino.size();
     if(n==0)    return NULL;
     mp.clear();
     for(int i=0; i<n; i++)  mp[ino[i]]=i;
     return solve(0,n-1,ino,0,n-1,post,n);
}
