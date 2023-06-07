/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

/*************** Merge two sorted list ************/
// head1->data <= head2->data (valid for this only)
Node* mergeSortedList(Node* head1, Node* head2)
{
    if(head1->child==NULL && head2->child==NULL){
        head1->child = head2;    return head1;
    }
    if(head1->child==NULL && head2->child!=NULL){
        head1->child = head2;    return head1;
    }
    Node* curr1 = head1;
    Node* next1 = curr1->child;
    Node* curr2 = head2;
    Node* next2 = curr2->child;
    while(curr2!=NULL && next1!=NULL)
    {
        if(curr2->data>=curr1->data && curr2->data<=next1->data){
            // update links
            curr1->child = curr2;
            next2 = curr2->child;
            curr2->child = next1;
            // update pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            curr1 = next1;
            next1 = next1->child;
            if(next1==NULL){
                curr1->child = curr2;
                return head1;
            }
        }
    }
    return head1;
}



Node* flattenLinkedList(Node* head) 
{
	if(!head || !head->next)	return head;
	Node* curr=head;
	while(curr->next){
		Node *h1=curr, *h2=curr->next;
		if(h1->data <= h2->data)
			curr = mergeSortedList(h1, h2);
		else
			curr = mergeSortedList(h2, h1);
		if(curr==h1){
			curr->next = h2->next;
			h2->next = NULL;
		} else if(curr==h2){
			h1->next = NULL;
		}
	}
	return curr;
}
