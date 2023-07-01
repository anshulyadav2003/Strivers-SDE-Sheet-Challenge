#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
unordered_map<int,bool> mp;
bool solve(BinaryTreeNode<int> *root, int k)
{
    if(!root)   return false;
    if(solve(root->left,k))  return true;
    
    // check 'rem' in mp
    int rem = k - root->data;
    if(mp[rem]) return true;
    mp[root->data] = true; // insert
    
    if(solve(root->right,k)) return true;
    return false;
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    mp.clear();
    return solve(root,k);
}