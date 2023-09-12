#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

node* createTree(node* root){

    cout << "Enter data : ";
    int data;
    cin >>data;
    root = new node(data);

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data to enter in the left of " << data << endl;
    root->left = createTree(root->left);

    cout << "Enter data to enter in the right of " << data << endl;
    root->right = createTree(root->right);

    return root;

}


void levelOrderTraverse(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();


        //old level is completed
        if(temp == NULL){
            cout << endl;
            
            //nodes still have child
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

void inorder(node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);

}

void preorder(node* root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);  
}

void postorder(node* root) {
    if(root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void createFromLevelOrder(node* &root) {
    queue<node*> q;

    cout << "Enter data : ";
    int data;
    cin >> data;

    root = new node(data);
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter data to add to left of " << temp->data << " ";
        
        cin >> data;
        if(data != -1) {
            node* add = new node(data);
            temp->left = add;
            q.push(temp->left);
        }

        cout << "Enter data to add to right of " << temp->data << " ";
        
        cin >> data;
        if(data != -1) {
            node* add = new node(data);
            temp->right = add;
            q.push(temp->right);
        }   
    }
    

}

int main(){
    node* root = NULL;

    // input string
    //1 2 7 -1 -1 11 -1 -1 5 17 -1 -1
    //1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1
    // root = createTree(root);

    createFromLevelOrder(root);

    levelOrderTraverse(root);
    // cout << "Inorder traversal----" << endl;
    // inorder(root);
    // cout << endl;

    // cout << "Preorder traversal----" << endl;
    // preorder(root);
    // cout << endl;

    // cout << "Postorder traversal----" << endl;
    // postorder(root);
    return 0;
}

