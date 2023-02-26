#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    } 

    ~Node(){
        int val = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }
};

void print(Node* tail){
    if(tail == NULL){
        cout << "List is empty, insert some elements first" << endl;
    }
    Node* temp = tail;
    do{
        cout << tail->data << " ";
        tail = tail->next;

    }while(tail != temp);
    cout << endl;
}

void insertAtPos(Node* &tail, int element, int d){
    // assuming element is present in the list

    // empty list
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else{//non empty list
        Node* curr = tail;

        while(curr->data != element){
            curr = curr->next;
        }
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node* &tail, int val){
    //empty list
    if(tail == NULL){
        cout << "List is empty, insert element first" << endl;
    }
    else{
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data != val){
            prev = curr;
            curr = curr->next;
        }
        

        prev->next = curr->next;
        

        //for 1 node linked list
        if(curr == prev){
            tail = NULL;
            delete curr;
        }

        else if(tail == curr){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

int main(){
    Node* tail = NULL;
    deleteNode(tail, 9);

    //insertion in empty list
    insertAtPos(tail, 5, 3);
    print(tail);

    insertAtPos(tail, 3, 12);
    insertAtPos(tail, 12, 13);
    print(tail);
    deleteNode(tail, 3);

    print(tail);
return 0;
}