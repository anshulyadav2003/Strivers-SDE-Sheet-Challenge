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

string serializeTree(TreeNode<int> *root)
{
    if(!root)   return "$,";
    string ans = to_string(root->data) + "," + serializeTree(root->left) +
                    serializeTree(root->right);
    return ans;
}

TreeNode<int>* makeTree(queue<string>& q)
{
    string curr = q.front();
    q.pop();
    if(curr=="$")   return nullptr;

    TreeNode<int>* root = new TreeNode<int>(stoi(curr));
    root->left = makeTree(q);
    root->right = makeTree(q);
    return root;
}

TreeNode<int>* deserializeTree(string &serialized)
{
    queue<string> q;
    string curr = "";
    for(auto it:serialized){
        if(it==','){
            q.push(curr);
            curr = "";
            continue;
        }
        curr += it;
    }
    if(curr!="")    q.push(curr);
    return makeTree(q);
}



