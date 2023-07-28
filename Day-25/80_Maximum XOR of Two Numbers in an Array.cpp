#include <bits/stdc++.h>

class Node{
public:
    Node* links[2];
    bool containsKey(int idx){
        return links[idx]!=nullptr;
    }
    Node* get(int idx){
        return links[idx];
    }
    void put(int idx, Node* node){
        links[idx] =  node;
    }
};

class Trie{
public:
    Node* root;
    Trie(){
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;
        for(int i=31; i>=0; i--){
            int bit = ((num>>i) & 1);
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    
    int findMaxXOR(int num) {
        Node* node = root;
        int currXOR=0;
        // For every ith bit find its opposite bit if not found then take that same bit.
        for(int i=31; i>=0; i--){
            int bit = ((num>>i)&1);
            if(node->containsKey(!bit)){
                currXOR = currXOR | (1<<i);
                node = node->get(!bit);
            } else{
                node = node->get(bit);
            }
        }
        return currXOR;
    }

};

int maximumXor(vector<int> arr) {
    int n=arr.size();
    Trie t;
    for(auto it: arr)   t.insert(it);

    int res=-1;
    for(auto it: arr)   res = max(res, t.findMaxXOR(it));
    return res;
}