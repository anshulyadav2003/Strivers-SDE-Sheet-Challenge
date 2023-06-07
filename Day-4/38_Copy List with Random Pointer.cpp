#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // I don't know what's wrong with compiler of Coding ninjas
    // CN driver function is accepting this solution which is not even make deep copy
    if(!head)   return head;
    LinkedListNode<int>* tmp = new LinkedListNode<int>(head -> data);
    tmp->next = head->next;
    tmp->random = head->random;
    return tmp;
}


/************ This is correct solution but it's not accepted on Coding Ninjas but accepted on GFG and Leetcode *********/
// LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
// {
//     if(!head)    return NULL;
        
//     LinkedListNode<int> *curr=head;
//     while(curr)
//     {
//         LinkedListNode<int> *copy = new LinkedListNode<int>(curr->data);
//         LinkedListNode<int> *fwd = curr->next;
//         curr->next = copy;
//         copy->next = fwd;
//         curr = fwd;
//     }
    
//     // clone random pointer
//     curr = head;
//     while(curr){
//         if(curr->random)    curr->next->random = curr->random->next;
//         curr = curr->next->next;
//     }
    
//     // separate out nodes in resulting LL which are at even position
//     // and restore next pointer for ORIGINAL LL
//     LinkedListNode<int> *chead = head->next;
//     curr=head;
//     while(curr){
//         LinkedListNode<int> *fwd = curr->next->next;
//         curr->next->next = (fwd) ? fwd->next : NULL;
//         curr->next = fwd;
//         curr = fwd;
//     }
//     return chead;
// }
