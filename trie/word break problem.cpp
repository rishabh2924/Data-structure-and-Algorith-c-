//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
struct node{
        node* child[26];
        bool isend;
        node(){
            for(int i=0;i<26;i++){
                child[i]=NULL;
            }
        } 
    };
     void insert(node *root,string s){
        int n=s.length();
        for(int i=0;i<n;i++){
            if(root->child[s[i]-'a']!=NULL)
            root=root->child[s[i]-'a'];
            else{
                root->child[s[i]-'a']=new node();
                root= root->child[s[i]-'a'];
            }
        }
        root->isend=true;
     }
class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    bool searchuntil(node *root,string s){
        node *temp=root;
        for(int i=0;i<s.length();i++){
            if(temp->child[s[i]-'a']!=NULL){
                temp=temp->child[s[i]-'a'];
            }
            else return false;
        }
        return temp&& temp->isend;
    }
    bool solve(node* root,string A){
        int n=A.length;
        if(n==0) return true;
        for(int i=1;i<=A.length();i++){
            if(searchuntil(root,A.substr(0,i))&& solve(i,A.substr(i,n-i))){
                return true;
            }
        }
        return false;
    }
   

    
    int wordBreak(string A, vector<string> &B) {
        //code here
        node *root=new node();
        for(auto it:B){
            insert(root,it);
        }
        return solve(root,A);

    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends