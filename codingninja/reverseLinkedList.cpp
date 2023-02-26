#include <bits/stdc++.h> 
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
void solve(LinkedListNode<int>* &head,LinkedListNode<int>* curr, LinkedListNode<int>* prev){
    if(curr == NULL){
        head = prev;
        return;
    }
    else{
        LinkedListNode<int>* forward = curr->next;
        solve(head, forward, curr);
        curr->next = prev;

    }
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if(head == NULL || head->next == NULL){
        return head;
    }
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* curr = head;


    solve(head,curr, prev);

    return head;
}