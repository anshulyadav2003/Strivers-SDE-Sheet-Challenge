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

    int checkInsertCount(string word)
    {
        int cnt=0;
        Node* head = root;
        for(auto ch:word){
            if(!head->links[ch-'a']){
                cnt++;
                head->links[ch-'a'] = new Node();
            }
            head = head->links[ch-'a'];
        }
        head->isEnd = true;
        return cnt;
    }
};

int distinctSubstring(string &word) {
    int ans=0;
    Trie t = Trie();
    for(int i=0; i<word.length(); i++){
        string s = word.substr(i);
        ans += t.checkInsertCount(s);
    }
    return ans;
}
