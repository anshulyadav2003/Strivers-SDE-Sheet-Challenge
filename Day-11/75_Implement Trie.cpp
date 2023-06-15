/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
class Node{
public:
    Node* links[26];
    bool isEnd=false;
};

class Trie {
public:
    Node* root;
    /** Initialize your data structure here. */
    Trie() {
        root= new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* head = root;
        for(auto ch: word){
            if(head->links[ch-'a']==NULL){
                head->links[ch-'a'] = new Node();
            }
            head = head->links[ch-'a'];
        }
        head->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* head = root;
        for(auto ch:word){
            if(!head->links[ch-'a'])    return false;
            head = head->links[ch-'a'];
        }
        return head->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* head = root;
        for(auto ch:prefix){
            if(!head->links[ch-'a'])    return false;
            head = head->links[ch-'a'];
        }
        return true;
    }
};