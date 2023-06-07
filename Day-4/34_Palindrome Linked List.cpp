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
/************** Reverse Singly Linked list **********/
LinkedListNode<int>* reverseList(LinkedListNode<int>* head) {
    if(!head || !head->next)   return head;
    LinkedListNode<int> *prev=NULL, *curr=head;
    while(curr){
        LinkedListNode<int> *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr=temp;
    }
    return prev;
}


bool isPalindrome(LinkedListNode<int> *head) {
    if(!head || !head->next)    return true;
    // divide list into two halves
    LinkedListNode<int> *slow=head, *fast=head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    LinkedListNode<int> *list1 = head, *list2=slow->next;
    list2 = reverseList(list2);
    
    while(list1 && list2){
        if(list1->data != list2->data)  return false;
        list1 = list1->next;
        list2 = list2->next;
    }
    return true;
}