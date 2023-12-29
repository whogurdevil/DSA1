#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int ind=0;

int ans=-1;

void solve(BinaryTreeNode<int>* root , int k){

    

     if(root  == NULL )return;

     solve(root->left, k);

     ind++;

     if(ind==k){

        ans=root->data;

     }

     solve(root->right, k);

}

 

int kthSmallest(BinaryTreeNode<int>* root, int k) {

    // Write your code here.

    ans=-1;

    ind=0;

    solve(root,k);

    return ans;

}

