//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
     node *left;
     node* right;
     node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
     }
};
class cmp{
    public:
    bool operator()(node*a,node*b){
        return a->data>b->data;
    }
};

// } Driver Code Ends
class Solution
{
	public:
    void preorder(node* root,vector<string> &ans,string temp){
        if(root->left==NULL&& root->right==NULL){
            ans.push_back(temp);
            return ;
        }
        preorder(root->left,ans,temp+'0');
        preorder(root->right,ans,temp+'1');
    }
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
            priority_queue<node*,vector<node*>,cmp> q;
            for (int i = 0; i < N; i++)
            {
                node* temp=new node(f[i]);
                q.push(temp);
            }
            while (q.size()>1)
            {
                node * left=q.top();
                q.pop();
                node * right=q.top();
                q.pop();
                node *temp=new node(left->data+right->data);
                temp->left=left;
                temp->right=right;
                q.push(temp);
            }
            node* root=q.top();
            vector<string>ans;
            string temp="";
            preorder(root,ans,temp);
            return ans;
		    
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends