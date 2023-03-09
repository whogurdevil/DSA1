/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/

void insertAtTail(Node* &tail,Node* curr){

    tail->next=curr;

    tail=curr;

}

Node* sortList(Node *head)

{

    // Write your code here.

Node* one=new Node(-1);

Node* two=new Node(-1);

Node* zero=new Node(-1);

Node* onehead=one;

Node* onetail=one;

Node* twohead=two;

Node* twotail=two;

Node* zerohead=zero;

Node* zerotail=zero;

Node* curr=head;

while(curr!=NULL){

    if(curr->data==0){

        insertAtTail(zerotail,curr);

    }

    else if(curr->data==1){

        insertAtTail(onetail,curr);

    }

    else{

        insertAtTail(twotail,curr);

    }

    curr=curr->next;

}

//merging

if(onehead==NULL){

    zerotail->next=twohead->next;

}

else{

    zerotail->next=onehead->next;

}

onetail->next=twohead->next;

twotail->next=NULL;

head=zerohead->next;

delete(zerohead);

delete(onehead);

delete(twohead);

return head;

}