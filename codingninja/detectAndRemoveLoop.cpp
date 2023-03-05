/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/

Node* floydDetect(Node* head){

    Node* slow = head;
    Node* fast = head;

    while(slow->next != NULL && fast->next != NULL){
        fast = fast -> next;
        if(fast->next != NULL){
            fast = fast->next;
        }
        slow = slow->next;

        if(slow == fast){
            return slow;
        }
    }

    return NULL;
}

Node* startLoop(Node* head){
    Node* intersect = floydDetect(head);
    if(intersect == NULL){
        return NULL;
    }
    Node* slow = head;

    while(slow != intersect){
        slow = slow -> next;
        intersect = intersect -> next;
    }

    return slow;
}

Node *removeLoop(Node *head)
{
    if(head == NULL){
        return NULL;
    }
    Node* startOfLoop = startLoop(head);
    if(startOfLoop == NULL){
        return head;
    }
    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop){
        temp = temp -> next;
    } 

    temp -> next = NULL;

    return head;
}