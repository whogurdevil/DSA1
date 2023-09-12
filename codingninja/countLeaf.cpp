/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
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
    
***********************************************************/
void solve(BinaryTreeNode<int> *root, int &count) {
    if(root == NULL) {
        return;
    }

    solve(root->left, count);

    if(root->left == NULL && root->right == NULL) {
        count++;
    }

    solve(root->right, count);
}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    int count = 0;
    solve(root, count);

    return count;
}