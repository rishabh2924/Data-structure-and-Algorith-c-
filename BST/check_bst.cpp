#include<bits/stdc++.h>

class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    bool check(BinaryTreeNode<int> *root,int min,int max){
        if(root==NULL){
            return true;
        }
        if(root->data>=min && root->data <= max){
            bool left =check(root->left,min,root->data);
            bool right =check(root->right,root->data,max);
            return left&& right;
            
            }
        else return false;

        
    }
    bool validateBST(BinaryTreeNode<int> *root) {
     return check(root,INT_MIN,INT16_MAX);
}