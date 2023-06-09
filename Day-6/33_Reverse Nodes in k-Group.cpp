#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
/************** Reverse Singly Linked list **********/
Node* reverseList(Node* head) {
    if(!head || !head->next)   return head;
    Node *prev=NULL, *curr=head;
    while(curr){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr=temp;
    }
    return prev;
}


Node* solve(Node *head, int block[], int n, int i){
	while(i<n && block[i]==0)	i++;
	if(i>=n)	return head;
	if(!head || !head->next)	return head;

	int size = block[i];	i++;
	Node *curr = head;
	while(size>1 && curr->next!=NULL){
		curr=curr->next;
		size--;
	}
	Node *last=head, *temp=curr->next;
	curr->next=NULL;
	head = reverseList(head);
	last->next = solve(temp,block,n,i);
	return head;
}


Node* getListAfterReverseOperation(Node *head, int n, int block[]){
	if(!head || !head->next)	return head;
	return solve(head,block,n,0);
}