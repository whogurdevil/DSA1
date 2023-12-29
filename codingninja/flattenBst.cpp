/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/

void getInorder(TreeNode<int>* &root, vector<int> &inorder){
    if(!root)
        return;

    getInorder(root->left, inorder);
    inorder.push_back(root->data);
    getInorder(root->right, inorder);

    return;
}

TreeNode<int> *makeBalancedTree(vector<int> inorder, int start, int end){
        if(start > end)
        return NULL;
    int mid = (start+end)/2;
    TreeNode<int>* root = new TreeNode<int>(inorder[mid]);
    root->left = makeBalancedTree(inorder, start, mid - 1);
    root->right = makeBalancedTree(inorder, mid + 1, end);

    return root;

    
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> inorder;
    getInorder(root, inorder);

    TreeNode<int>* ans = makeBalancedTree(inorder, 0, inorder.size()-1);
    return ans;
}
