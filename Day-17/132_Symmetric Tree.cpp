/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
bool solve(BinaryTreeNode<int>* r1, BinaryTreeNode<int>* r2)
{
    if(!r1 && !r2)  return true;
    if(!r1 || !r2)  return false;
    if(r1->data != r2->data)    return false;
    bool l = solve(r1->left, r2->right);
    bool r = solve(r1->right, r2->left);
    return l&&r;
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(!root)   return true;
    if(!root->left && !root->right) return true;

    return solve(root,root);    
}