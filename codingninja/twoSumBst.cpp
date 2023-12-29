#include <bits/stdc++.h> 
// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
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
***************/

void getInorder(BinaryTreeNode<int>* &root, vector<int> &inorder){
    if(root == NULL)
        return;

    getInorder(root->left, inorder);

    inorder.push_back(root->data);

    getInorder(root->right, inorder);

    return;
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector<int> inorder;
    
    getInorder(root, inorder);

    int start = 0;
    int end = inorder.size() - 1;
    int sum = 0;
    while(end > start){
        sum = inorder[start] + inorder[end];
        if(sum == target)
            return true;
        else if(sum < target)
            start += 1;
        else
            end -= 1;
    }
    return false;
}