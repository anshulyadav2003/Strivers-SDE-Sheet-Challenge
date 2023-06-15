#include <bits/stdc++.h> 

class Node{
public:
    Node* links[26];
    bool isEnd=false;
};

class Trie{
public:
    Node* root;
    Trie(){
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* head = root;
        for(auto ch: word){
            if(!head->links[ch-'a']){
                head->links[ch-'a'] = new Node();
            }
            head = head->links[ch-'a'];
        }
        head->isEnd = true;
    }

    bool checkGivenCondition(string word){
        Node* head = root;
        for(auto ch:word){
            head = head->links[ch-'a'];
            if(head->isEnd==false)  return false;
        }
        return true;
    }
};

string completeString(int n, vector<string> &arr){
    Trie t = Trie();
    for(auto str: arr){
        t.insert(str);
    }

    string ans="";
    for(auto str: arr){
        if(t.checkGivenCondition(str)==false) continue;
        if(ans.length()<str.length())   ans = str;
        else if(ans.length()==str.length()) ans = min(ans,str);
    }
    return ans=="" ? "None" : ans;
}