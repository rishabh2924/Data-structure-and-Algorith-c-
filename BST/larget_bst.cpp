#include<bits/stdc++.h>
#include<iostream>
using namespace std;

   
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };


class info{
    public:
    int mini;
    int maxi;
    bool isbst;
    int size;
};
info solve(TreeNode<int>* root,int &ans){
    if(root==NULL){
        return {INT_MAX,INT_MIN,true,0};
    }
    info left=solve(root->left,ans);
    info right=solve(root->right,ans);
    info curr;
    curr.size=left.size+right.size+1;
    curr.maxi=max(root->data,right.maxi);
    curr.mini=min(root->data,left.mini);
    
    if(left.isbst && right.isbst&& (left.maxi<root->data && right.mini>root->data)){
        curr.isbst=true;
    }
    else {
        curr.isbst=false;
    }
    if(curr.isbst){
        ans=max(ans,curr.size);
    }
    return curr;
}
int largestBST(TreeNode<int>* root) 
{
    int maxsize=0;
    info temp=solve(root,maxsize);
    return maxsize;
}
