/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/


Node *addTwoNumbers(Node *first, Node *second)
{
    int len1 = 0;
    Node* temp=first;
    while(temp){
        temp=temp->next;    len1++;
    }
    int len2 = 0;
    temp=second;
    while(temp){
        temp=temp->next;    len2++;
    }
    if(len1<len2)   return addTwoNumbers(second,first);
    
    int c=0;
    Node *h1=first, *h2=second;
    Node* last;
    while(h1 && h2)
    {
        int sum = h1->data + h2->data + c;
        c = sum/10;
        h1->data = sum%10;
        if(h1->next==NULL)  last=h1;
        h1 = h1->next;
        h2 = h2->next;
    }
    while(h1){
        int sum = h1->data + c;
        c=  sum/10;
        h1->data = sum%10;
        if(h1->next==NULL)  last=h1;
        h1 = h1->next;
    }
    if(c==1){
        Node* carrynode = new Node(c);
        last->next = carrynode;
    }
    
    return first;
}
