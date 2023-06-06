#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

void deleteNode(LinkedListNode<int> * node) {
    node->data = node->next->data;
    LinkedListNode<int> *temp = node->next;
    node->next = node->next->next;
    delete(temp);


    // LinkedListNode<int> *curr=node;
    // LinkedListNode<int> *last;
    // while(curr->next){
    //     int temp = curr->data;
    //     curr->data = curr->next->data;
    //     curr->next->data = temp;
    //     if(curr->next->next == NULL)    last = curr;
    //     curr = curr->next;
    // }
    // last->next = NULL;
}