#include <bits/stdc++.h> 
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int height;
    int leftIndex;
    int rightIndex;

    Node(int h, int li, int ri) {
        height = h;
        leftIndex = li;
        rightIndex = ri;
    }
};

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int n){
    int maxHeight = 0;
    queue<Node> q;
    if(n>=1) {
        Node node(0, 0, n-1);
        q.push(node);
    }

    unordered_map<int,int> mp;
    for(int i=0; i<n; i++) {
        mp[inorder[i]] = i;
    }

    for(int i=0; i<n; i++) {
        Node curr = q.front();
        q.pop();

        maxHeight = max(curr.height, maxHeight); // updating tree height

        int li = curr.leftIndex;
        int ri = curr.rightIndex;
        int rootIndex;

        rootIndex = mp[levelOrder[i]];
        if(rootIndex - 1 >= li) {
            Node leftSubTree(curr.height + 1, li, rootIndex - 1);
            q.push(leftSubTree);
        }

        if(rootIndex + 1 <= ri) {
            Node rightSubTree(curr.height + 1, rootIndex + 1, ri);
            q.push(rightSubTree);
        }
    }

    return maxHeight;
}




/************************ TLE ******************/
// step 1: contruct tree from INORDER and LEVEL ORDER
// step 2: then find height of tree
class Node{
public:
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left=right=nullptr;
    }
};

unordered_map<int,int> mp;
// constructing tree using INORDER and LEVEL ORDER traversal
Node* constructTree(vector<int>& ino, vector<int>&lo, int i, int j) {
    if(i>=j)    return nullptr;
    if(i==j)    return (new Node(ino[i]));

    int idx = i;
    for(int k=i+1; k<=j; k++){
        if(mp[ino[k]] < mp[ino[idx]])   idx=k;
    }
    Node* root = new Node(ino[idx]);
    root->left = constructTree(ino, lo, i, idx-1);
    root->right = constructTree(ino, lo, idx+1, j);
    return root;
}

int height(Node* root){
    if(!root)   return 0;
    int l = height(root->left);
    int r = height(root->right);
    return 1+max(l,r);
}

int heightOfTheTree(vector<int>& ino, vector<int>& lo, int n){
    mp.clear();
    for(int i=0; i<n; i++)  mp[lo[i]]=i;
    Node* root = constructTree(ino,lo,0,n-1);

    return height(root);
}
