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

void delFromPos(int pos, Node* &head){
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

int main(){
    
    Node* node = new Node(10);
    print(node);
    Node* head = node;
    Node* tail = node;
    insertAtHead(head, 20);
    print(head);
    insertAtTail(tail, 30);
    print(head);
    insertAtPos(head, tail, 4, 350);
    print(head);
    delFromPos(3, head);
    print(head);
return 0;
}   