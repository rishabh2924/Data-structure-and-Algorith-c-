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
    int findposition(int in[],int ele,int n){
        for (int i = 0; i < n; i++)
        {
           if(in[i]==ele){
            return i;
           }
           else return -1;
        }
        
    }
    Node *construct(int in[],int pre[], int n,int& index,int Inorderstart,int InorderEnd){
        if(index>=n|| Inorderstart>InorderEnd){
            return NULL;
        }
        int ele=pre[index++];
        int position =findposition(in,ele,n);
        Node* root=new Node(ele);
        root->left=construct(in,pre,n,index,0,position-1);
        root->right=construct(in,pre,n,index,position+1,n);
        return root;

    }
    Node* buildTree(int in[],int pre[], int n)
    {
       int index=0;
       Node * ans=construct(in,pre,n,index,0,n-1);
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