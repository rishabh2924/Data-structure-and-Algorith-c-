#include<bits/stdc++.h>
#include<vector>
template <typename T>
class BinaryTreeNode {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
    BinaryTreeNode<int>* solve(vector<int> &preorder,int mini,int maxi, int &i){
        if(i>preorder.size()){
            return NULL;
        }
        if(preorder[i]<mini && preorder[i]>maxi){
            return NULL;
        }
        BinaryTreeNode<int>* newnode= new BinaryTreeNode<int>(preorder[i++]);
        newnode->left=solve(preorder,mini,root->data,i);
        newnode->right=solve(preorder,root->data,maxi,i);
        return newnode;
    }
    BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int mini=INT_Min;
    int maxi=INT_MAX;
    int i=0;
    return solve(preorder,mini,maxi,i);
}