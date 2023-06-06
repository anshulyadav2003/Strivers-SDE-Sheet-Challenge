#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(!first && !second)   return NULL;
    if(!first)   return second;
    if(!second)  return first;
    
    if(first->data > second->data)  return sortTwoLists(second,first);

    Node<int> *curr1=first, *curr2=second;
    while(curr2 && curr1){
        if(!curr1->next){
            curr1->next = curr2;    return first;
        }
        if(curr1->data <= curr2->data && curr2->data <= curr1->next->data){
            Node<int> *temp1 = curr1->next;
            Node<int> *temp2 = curr2->next;
            curr1->next = curr2;
            curr2->next = temp1;
            curr1 = curr2;
            curr2 = temp2;
        } else{
            curr1 = curr1->next;
        }
    }
    return first;
}
