#include <bits/stdc++.h> 

class Node{
public: 
    Node* links[26];
    int cntPrefix= 0;
    int cntEnd=0;
};

class Trie{
public:
    Node* root;

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* head = root;
        for(auto ch:word){
            if(!head->links[ch-'a']){
                head->links[ch-'a'] = new Node();
            }
            head = head->links[ch-'a'];
            head->cntPrefix++;
        }
        head->cntEnd++;
    }

    int countWordsEqualTo(string &word){
        Node* head = root;
        for(auto ch:word){
            if(!head->links[ch-'a'])    return 0;
            head = head->links[ch-'a'];
        }
        return head->cntEnd;
    }

    int countWordsStartingWith(string &word){
        Node* head = root;
        for(auto ch:word){
            if(!head->links[ch-'a'])    return 0;
            head = head->links[ch-'a'];
        }
        return head->cntPrefix;
    }

    void erase(string &word){
        Node* head = root;
        for(auto ch:word){
            head = head->links[ch-'a'];
            head->cntPrefix--;
        }
        head->cntEnd--;
    }
};
