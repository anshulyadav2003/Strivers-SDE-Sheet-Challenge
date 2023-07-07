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

/**************** Stack **************/
class BSTiterator {
public:
    stack<TreeNode<int>*> st;
    BSTiterator(TreeNode<int> *root) {
        while(root){
            st.push(root);
            root=root->left;
        }
    }

    int next() {
        if(st.empty())  return -1;
        auto curr = st.top();   st.pop();
        TreeNode<int>* temp = curr->right;
        while(temp){
            st.push(temp);
            temp=temp->left;
        }
        return curr->data;
    }

    bool hasNext() {
        return st.size()>0;
    }
};



/***************** Vector ****************/
class BSTiterator {
public:
    vector<int> ino;
    int i,n;
    BSTiterator(TreeNode<int> *root) {
        fillIno(root,ino);
        i=0;
        n = ino.size();
    }

    void fillIno(TreeNode<int>*root, vector<int>&ino){
        if(!root)   return;
        fillIno(root->left,ino);
        ino.push_back(root->data);
        fillIno(root->right,ino);
    }

    int next() {
        return ino[i++];
    }

    bool hasNext() {
        return i<n;
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/