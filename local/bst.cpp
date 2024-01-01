#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
  int data;
  Node *left;
  Node *right;

  Node(int d) {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};

Node* insertInBst(Node* &root, int d){
  if(root == NULL){
    Node* temp = new Node(d);
    root = temp;
    return root;
  } 
  
  if(d <= root->data){
    root->left = insertInBst(root->left, d);
  }
  else{
    root->right = insertInBst(root->right, d);
  }
  return root;
}

void getInput(Node* &root){
  int data;

  while(data != -1){
    insertInBst(root, data);
    cin >> data;
  }
}

void levelOrderTraversal(Node* &root){
  if(root == NULL)
      return;

  queue<Node*> q;
  q.push(root);
  q.push(NULL);
  while(!q.empty()){
    
    Node* temp = q.front();
    q.pop();
  
    if(temp == NULL){
      cout << endl;

      if(!q.empty()){
        q.push(NULL);
      }
    }
    else{
      cout << temp->data << " ";
      if(temp->left){
        q.push(temp->left);
      }
      if(temp->right){
        q.push(temp->right);
      }
    }
  }
}

int main() {
  Node* root = NULL;
  cout << "Enter Value to insert in bst: ";
  getInput(root);
  levelOrderTraversal(root);
}
