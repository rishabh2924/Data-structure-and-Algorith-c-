#include<iostream>
#include<string.h>
using namespace std;
class trienode{
    public:
    char data;
    trienode* children[26];
    int wordcount;
    bool terminated;

    trienode(char c){
        data=c;
        for (int i = 0; i < 26; i++)
        {
            children[i]=NULL;
        }
        wordcount=0;
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
                root->wordcount++;
                root->children[index]=child;
            }
            insertuntil(child,word.substr(1));

    }
    void insertword(string word){
        insertuntil(root,word);
    }
    void lcp(string str,string &ans){
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            if(root->wordcount==1){
                ans.push_back(ch);
                int index=ch-'a';
                root=root->children[index];
            }
            else break;
            if(root->terminated){
                break;
            }
        }
    }
};
string longestCommonPrefix(vector<string> &arr, int n)
{
    trie* t=new trie();
    string ans="";
    for(int i=0;i<n;i++){
        t->insertword(arr[i]);
    }
    t->lcp(arr[0],ans);
    return ans;
}


