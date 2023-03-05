#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        if(this != NULL){
            delete next;
            this->next = NULL;
        }
    }

};


void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);

    temp->next = head;
    head = temp;

}

void insertAtTail(Node* &tail, int data){
    Node *temp = new Node(data);

    tail->next = temp;
    tail = temp;
}

void insertAtPos(Node* &head,Node* &tail , int pos, int data){
    //head
    if(pos == 1){
        insertAtHead(head, data);
        return;
    }
    

    Node* temp = head;
    for(int i = 1; i < pos-1; i++){
        temp = temp->next;
    }
    if(temp->next == NULL){
        insertAtTail(tail, data);
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void delFromPos(int pos, Node* head){
    if(pos == 1){
        Node* temp = head;
        head = head -> next;

        //delete memory
        temp->next = NULL;  //condition to satisfy destructor 
        delete temp;
    }
    else{
        int cnt = 1;
        Node* curr = head;
        Node* prev = NULL;
        while(cnt < pos){
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

//detects the point of intersection of slow and fast
Node* floydDetect(Node* head){
    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL) {
        fast = fast->next;
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

//returns starting node of loop
Node* detectLoop(Node* head){
    Node* intersection = floydDetect(head);
    Node* slow = head;

    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
    
}

void removeLoop(Node* &head){
    if(head == NULL)
        return;
    
    Node* startingOfLoop = detectLoop(head);
    Node*temp = startingOfLoop;

    while(temp->next != startingOfLoop){
        temp = temp->next;
    }

    temp->next = NULL;
}

int main(){
    Node* node = new Node(10);
    Node* head = node;
    Node* tail = node;
    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    Node* temp = tail;
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);

    tail->next = temp;

    print(head);

    Node* check = floydDetect(head);
    if(check != NULL){
        cout << "Node is in loop and intersected at " << check->data << endl;
    }
    else{
        cout << "There is no loop in list" <<  endl;
    }

    Node* loopStart = detectLoop(head);
    cout << "starting point of loop is " << loopStart->data << endl;

    removeLoop(head);
    print(head);


return 0;
}