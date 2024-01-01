/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

void getInorder(TreeNode *root, vector<int>& inorder){

    if(!root) 
        return;

    getInorder(root->left,inorder);

    inorder.push_back(root->data);

    getInorder(root->right,inorder);

}

// TreeNode* makeTree(vector<int> &inorder, int &index, int min, int max){
//     if(index > inorder.size())
//         return NULL;

//     if(inorder[index] < min || inorder[index] > max)
//         return NULL;

    
//     TreeNode* root = new TreeNode(inorder[index++]);

//     root->left = makeTree(inorder, index, min, root->data);
//     root->right = makeTree(inorder, index, root->data, max);

//     return root;
// }

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int> inorder1;
    getInorder(root1, inorder1);
    vector<int> inorder2;
    getInorder(root2, inorder2);

    int i = 0, j = 0;

    vector<int> mergedInorder;

    while(i < inorder1.size() && j < inorder2.size()){
        if(inorder1[i] < inorder2[j])
            mergedInorder.push_back(inorder1[i++]);
        else
            mergedInorder.push_back(inorder2[j++]);
    }

    while(i < inorder1.size())
        mergedInorder.push_back(inorder1[i++]);

    while(j < inorder2.size())
        mergedInorder.push_back(inorder2[j++]);

    // TreeNode* ans = makeTree(mergedInorder, 0, INT_MIN, INT_MAX);

    return mergedInorder;

}