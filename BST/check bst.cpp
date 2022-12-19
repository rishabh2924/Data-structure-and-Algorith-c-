//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};




// } Driver Code Ends
class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool solve(Node *root,int mini,int maxi){
        if(root==NULL){
            return true;
        }
        if(root->data>mini && root->data<maxi){
        bool left= solve(root->left,mini,root->data);
        bool right=solve(root->right,root->data,maxi);
        return left&right;
        }
        else return false;
    }
    bool isBST(Node* root) 
    {
        // Your code here
       
        return solve(root,INT_MIN,INT_MAX);
    }

    //********************another approach*********
    pair<int,bool> solve(Node* root){
        if(root==NULL){
            return {0,true};
        }
        if(root->left==NULL && root->right==NULL){
            return {root->data,true};
        }
        pair<int,bool> left=solve(root->left);
        pair<int,bool> right=solve(root->right);
        pair<int,bool> ans;
        ans.first=root->data;
        if(root->data>left.first && root->data<right.first){
            ans.second=left.second&right.second;
        }
        else ans.second=false;
    }


    bool isBST(Node* root) 
    {
        // Your code here
        pair<int,bool> ans=solve(root);
        return ans.second;

    }
};




//{ Driver Code Starts.

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

void inorder(Node *root, vector<int> &v)
{
    if(root==NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {
 
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
    string s; 
    getline(cin, s);
    Node* root = buildTree(s);
    Solution ob;
    if(ob.isBST(root)) 
        cout<<"1\n";
        
    else
        cout<<"0\n";
   }
   return 0;
}


// } Driver Code Ends