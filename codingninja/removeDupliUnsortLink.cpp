#include<bits/stdc++.h>
Node *delet(Node *p,Node *q){
    q->next = p->next;
    //free(p);
    return p->next;
}


Node *removeDuplicates(Node *head)
{
    // Write your code here
    if(!head)
    return NULL;
    unordered_map<int,int> ind;
    Node *p = head;
    Node *q = NULL;
    while(p){
        if(ind.count(p->data)){
            p = delet(p,q);
        }
        else{
            ind[p->data]++;
            q = p;
            p = p->next;   
        }
    }
    return head;
}

