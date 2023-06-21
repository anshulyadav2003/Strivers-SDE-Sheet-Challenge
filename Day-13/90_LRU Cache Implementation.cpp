#include <unordered_map>
class Node{
public:
    int key, val;
    Node *next, *prev;
    Node(int key, int val){
        this->key = key;
        this->val = val;
    }
};

class LRUCache {
public:
    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);
    int size;
    unordered_map<int,Node*> mp;
    LRUCache(int capacity)
    {
        size = capacity;
        head->next=tail;  tail->prev=head;
    }

    int get(int key)
    {
        if(mp.find(key)==mp.end())  return -1;
        Node* curr = mp[key];
        // delete curr from its current position
        Node *l=curr->prev, *r=curr->next;
        l->next = r;
        r->prev = l;
        // and insert just after head to make it recently used 
        Node* temp = head->next;
        head->next = curr;
        curr->prev = head;
        curr->next = temp;
        temp->prev = curr;
        return curr->val;
    }

    void put(int key, int value)
    {
        Node* curr;
        // do not exist currently in cache
        if(mp.find(key)==mp.end()){
            curr = new Node(key,value);
            // if oversize then delete least recently used {key,val} i.e, just before tail
            if(mp.size()==size){
                Node* toDel = tail->prev;
                mp.erase(toDel->key); // erase from map
                Node *l=toDel->prev, *r=toDel->next;
                l->next = r;
                r->prev = l;
                toDel->next=nullptr, toDel->prev=nullptr;
                delete(toDel);
                
            }
        } 
        // exist currently in cache
        else{ // update it and delete from current position
            curr = mp[key];
            curr->val = value;
            // delete curr from its current position
            Node *l=curr->prev, *r=curr->next;
            l->next = r;
            r->prev = l;
        }
        // and insert just after head to make it recently used
        Node* temp = head->next;
        head->next = curr;
        curr->prev = head;
        curr->next = temp;
        temp->prev = curr;
        mp[key] = curr;
    }
};
