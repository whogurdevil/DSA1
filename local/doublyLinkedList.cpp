#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int d){
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    } 

    ~Node(){
        int val = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }
};

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node* head){
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }

    return len;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }

    Node *temp = new Node(data);

    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node* &tail, Node* &head, int data){
    if(tail == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    Node* temp = new Node(data);
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}

void insertAtPos(Node* &head, Node* &tail, int pos, int data){
    if(pos == 1){
        insertAtHead(head, tail, data);
        return;
    }

    Node* temp = head;

    int cnt = 1;
    while(cnt < pos-1){
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL){
        insertAtTail(tail, head, data);
        return;
    }


    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    nodeToInsert->prev = temp;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
}


void deleteNode(Node* &head, Node* &tail, int pos){

    if(pos == 1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next; 
        temp->next = NULL;
        delete temp;

        return;
    }

    Node* curr = head;
    Node* prev = NULL;

    int cnt = 1;
    while(cnt < pos){
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    curr -> prev = NULL;
    prev -> next = curr -> next;
    curr -> next = NULL;
    delete curr;
}


int main(){
    Node* head = NULL;
    Node* tail = NULL;

    print(head);

    cout <<  "Total length is : " << getLength(head) << endl;

    insertAtHead(head, tail, 56);

    print(head);
    insertAtHead(head, tail, 32);

    print(head);
    insertAtTail(tail, head ,45);
    print(head);
    insertAtPos(head, tail, 1, 4637);
    print(head);
    insertAtPos(head, tail, 3, 4637);
    print(head);
    insertAtPos(head, tail, 6, 4637);
    print(head);

    deleteNode(head,tail,6);
    print(head);


return 0;
}