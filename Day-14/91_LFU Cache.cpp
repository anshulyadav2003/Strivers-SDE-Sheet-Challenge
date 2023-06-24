#include <bits/stdc++.h>

class Node{
public:
    int key, val;
    Node *next, *prev;
    Node(int key, int val){
        this->key = key;
        this->val = val;
    }
};

class LFUCache {
public:
    unordered_map<int,pair<Node*,Node*>> mp;
    unordered_map<int,pair<Node*,int>> loc;
    int size;
    LFUCache(int capacity){
        size=capacity;
    }

    int get(int key)
    {
        if(loc.find(key)==loc.end())    return -1;
        Node* x = loc[key].first;
        int freq = loc[key].second;
        freq++;
        int ans = x->val;
        // delete from current freqList
        Node *l=x->prev, *r=x->next;
        l->next=r;  r->prev=l;
        // add in higher freqList
        if(mp.find(freq)==mp.end()){
            Node* head = new Node(-1,-1);
            Node* tail = new Node(-1,-1);
            head->next=x;   x->prev=head;
            x->next=tail;   tail->prev=x;
            mp[freq] = {head,tail};
        } else{
            Node* head = mp[freq].first;
            Node* temp = head->next;
            head->next=x;   x->prev=head;
            x->next=temp;   temp->prev=x;
        }
        loc[key] = {x,freq};
        return ans;
    }




    void put(int key, int value)
    {
        Node *x;    int freq;
        if(loc.find(key)!=loc.end()){
            x = loc[key].first;
            freq = loc[key].second;
            freq++;
            x->val = value; // update value as it 'key' was already existing
            // delete from current freqList
            Node *l=x->prev, *r=x->next;
            l->next=r;  r->prev=l;
        } 
        else{
            int lf=1;
            // while(mp.find(lf)==mp.end())    lf++;
            if(loc.size()==size){ // memory full -> remove LFU
                Node *head=mp[lf].first,    *tail=mp[lf].second;
                Node *toDel=tail->prev;
                Node *l=toDel->prev, *r=toDel->next;
                l->next=r;  r->prev=l;
                toDel->next=NULL;   toDel->prev=NULL;
                loc.erase(toDel->key);
                delete(toDel);
                if(head->next==tail) mp.erase(lf);
            }
            x = new Node(key,value);
            freq = 1;
        }
        // add in new freqList
        if(mp.find(freq)==mp.end()){ // if this is first element in DLL of increased 'freq'
            Node* head = new Node(-1,-1);
            Node* tail = new Node(-1,-1);
            head->next=x;   x->prev=head;
            x->next=tail;   tail->prev=x;
            mp[freq] = {head,tail};
        } else{
            Node* head = mp[freq].first;
            Node* temp = head->next;
            head->next=x;   x->prev=head;
            x->next=temp;   temp->prev=x;
        }
        loc[key] = {x,freq};
    }
};
