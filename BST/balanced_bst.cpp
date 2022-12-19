#include<bits/stdc++.h>
#include<vector>
template <typename T>
    class TreeNode
    {
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
    void inorder(TreeNode<int>* root, vector<int>& val){
    if(root==NULL){
        return ;
    }
    inorder(root->left,val);
    val.push_back(root->data);
    inorder(root->right,val);
}
TreeNode<int>* solve(vector<int> val,int s, int e){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    TreeNode<int>* newNode=new TreeNode<int>(val[mid]);
    newNode->left=solve(val,0,mid-1);
    newNode->right=solve(val,mide+1,e);
    return newNode;

}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> val;
    inorder(root,val);
    return solve(val,0,val.size()-1);
}