/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */
int findLenLL(Node* head){
     if(!head) return 0;
     return 1+findLenLL(head->next);
}

Node *rotate(Node *head, int k) {
    if(!head || !head->next)    return head;
    int len = findLenLL(head);
    k = k%len;
    if(k==0)  return head;
    
    Node *a=head, *b=head;
    while(k--){
        b=b->next;
        if(b==NULL && k>0)    b=head;
    }
    if(b==NULL)    return head;
    while(b->next){
        a = a->next;
        b = b->next;
    }
    Node* ans = a->next;
    a->next = NULL;
    b->next = head;
    return ans;
}