/************************************************************

    Following is the linked list node structure.
    
    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };
    
************************************************************/

Node * uniqueSortedList(Node * head) {
    if(head == NULL){
        return head;
    }
    
    Node* curr = head -> next;
    Node* prev = head;

    int ele = prev->data;

    while(curr != NULL){
      if (ele == curr->data) {
        prev->next = curr->next;
        curr->next = NULL;
        curr = prev->next;
        ele = prev->data;
        continue;
      }
      prev = prev->next;
      curr = curr->next;
        ele = prev->data;

    }

    return head;
}