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

bool solve(BinaryTreeNode<int>* &root, int min, int max){
    if(root == NULL)
        return true;

    int left = solve(root->left, min, root->data);
    int right= solve(root->right, root->data, max);

    if(left && right && root->data <= max && root->data >= min){
        return true;
    }
    
    return false;

}

bool validateBST(BinaryTreeNode<int> *root) {
    return solve(root, INT_MIN, INT_MAX);
}