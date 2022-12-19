//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 


class Solution{
  public:
    //Function to merge K sorted linked list.
    Node* merge(Node* a,Node* b){
        if(a==NULL){
            return b;
        }
           
        if(b==NULL){
            return a;
        }
        Node* temp=  new Node(0);
            Node *res=temp;
        while(a!=NULL && b!=NULL){
            
            if(a->data>b->data){
                temp->next=b;
                temp=b;
                b=b->next;
            }
            else{
                temp->next=a;
                temp=a;
                a=a->next;
            }
           
        }
        if(a==NULL){
            temp->next=b;
           }
           else{
            temp->next=a;
           }
           return res->next;
    }
    Node * mergeKLists(Node *arr[], int K)
    {
       Node*firstnode= arr[0];
       for(int i=1;i<K;i++){
            firstnode=merge(firstnode,arr[i]);
       }
       return firstnode;
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends