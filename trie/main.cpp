#include<iostream>
using namespace std;
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
    bool searchuntil(trienode* root,string word){
        if(word.length()==0){
            return root->terminated;
        }
        int index=word[0]-'a';
        trienode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else return false;
        return searchuntil(child,word.substr(1));
    }
    bool searchword(string word){
       return  searchuntil(root,word);
    }
    bool trieEmpty(trienode *root){
    for(int i = 0 ; i < 26 ; i++){
        if(root->children[i]){
            return false;
        }
    }    
    return true;
}
    void deleteuntil(trienode* root,string word){
        if(word.length()==0){
            root->terminated=false;
            return ;
        }
        
        int index=word[0]-'a';
        trienode* child;
        if(root->children[index]!=NULL){
        child=root->children[index];
        deleteuntil(child,word.substr(1));
          if(trieEmpty(root) && root->terminated == false){
        // Node deleted
        delete(root); 
        root = NULL;
    }
        }
        else {
            cout<<"no existence"<<endl;
        }

    }
    void deleteword(string word){
         deleteuntil(root,word);
        
        
    }
};
int main(){
    trie* t=new trie();
    t->insertword("my");
    t->insertword("name");
    t->insertword("is");
    t->insertword("rishabh");
    t->insertword("aggarwal");
    cout<<"present or not  "<< t->searchword("name")<<endl;
    t->deleteword("name");
    t->deleteword("nams");
    cout<<"present or not  "<< t->searchword("name ")<<endl;
    cout<<"present or not  "<< t->searchword("nadf ")<<endl;

}