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
int dia=0;
int solve(TreeNode<int>* root)
{
    if(!root)   return 0;
    int l = solve(root->left);
    int r = solve(root->right);
    int len = (l+r+1);
    dia = max(dia,len-1);
    return 1+max(l,r);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    if(!root)   return 0;
    dia=0;
	solve(root);
    return dia;
}
