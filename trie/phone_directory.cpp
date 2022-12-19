//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class trienode{
    public:
    char data;
    trienode* children[26];
    bool terminated;

    trienode(char c){
        data=c;
        for (int i = 0; i < 26; i++)
        {
            children[i]=0;
        }
        terminated=false;
    }
};
class trie{
    public:
    trienode* root;
    trie(){
    root=new trienode('\0');}
    void insertuntil(trienode* root,string word){
            if(word.length()==0){
                root->terminated=true;
                return;
            }
             int index=word[0]-'a';
            trienode *child;
            if(root->children[index]!=NULL){
                child=root->children[index];
            }
            else{
                child=new trienode(word[0]);
                root->children[index]=child;
            }
            insertuntil(child,word.substr(1));

    }
    void insertword(string word){
        insertuntil(root,word);
    }
    void printsuggestion(trienode* curr,vector<string>& temp,string prefix){
        if(curr->terminated){
            temp.push_back(prefix);
        }
        for ( char c='a';c<='z';c++)
        {
            trienode* next=curr->children[c-'a'];
            if(next!=NULL){
                prefix.push_back(c);
                printsuggestion(next,temp,prefix);
                prefix.pop_back();
            }
        }
        
    }
    vector<vector<string>> getsuggestion(string str){
            trienode* prev=root;
            
            vector<vector<string>> output;
            string prefix="";
            for (int i = 0; i < str.length(); i++)
            {
                char lastch=str[i];
                prefix.push_back(str[i]);
                trienode* curr=prev->children[lastch-'a'];
                if(curr==NULL){
                    break;
                }
                vector<string> temp;
                printsuggestion(curr,temp,prefix);
                output.push_back(temp);
                temp.clear();
                prev=curr;

            }
          return output;  
    }
};
class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        trie* t=new trie();
        for (int i = 0; i < n; i++)
        {
            t->insertword(contact[i]);
        }
        return t->getsuggestion(s);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends