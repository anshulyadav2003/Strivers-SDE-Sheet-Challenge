/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

*****************************************************************/

Node* findIntersection(Node *f, Node *s)
{
    Node *ptr1 = f;
    Node *ptr2 = s;
    while(ptr1 != ptr2){
        if(ptr1 == NULL){
            ptr1 = s;   // put pointer of first list at head of second list
        }
        else{
            ptr1 = ptr1 -> next;
        }
        if(ptr2 == NULL){
            ptr2 = f;   // put pointer of second list at head of first list
        }
        else{
            ptr2 = ptr2 -> next;
        }
    }
    return ptr1;
}