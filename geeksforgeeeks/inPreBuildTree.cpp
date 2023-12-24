//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    // void createMapping(int arr[], map<int, int> &nodeToPos, int n){
    //     for(int i = 0; i < n; i++){
    //         nodeToPos[arr[i]] = i;
    //     }
    // }
    int findIndex(int arr[], int &startIndex, int &endIndex, int key){
        for(int i = startIndex; i <= endIndex; i++){
            if(arr[i] == key)
                return i;
        }
        return -1;
    }
    
    Node* solve(map<int, int> &nodeToPos, int in[], int pre[], int &preOrderIndex, int inOrderStart, int inOrderEnd, int n){
        if(preOrderIndex >= n || inOrderStart > inOrderEnd){
            return NULL;
        }
        
        int ele = pre[preOrderIndex++];
        Node* root = new Node(ele);
        // int position = nodeToPos[ele];
        int position = findIndex(in, inOrderStart, inOrderEnd, ele);
        
        root->left = solve(nodeToPos, in, pre, preOrderIndex, inOrderStart, position-1, n);
        root->right = solve(nodeToPos, in, pre, preOrderIndex, position+1, inOrderEnd, n);
        
        return root;
        
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex = 0;
        map<int, int> nodeToPos;
        // createMapping(in, nodeToPos, n);
        Node* ans = solve(nodeToPos, in, pre, preOrderIndex, 0, n-1, n);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends