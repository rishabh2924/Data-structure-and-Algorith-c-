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
    
};

void inorder(BinaryTreeNode<int>* root, vector<int>& val){
    if(root==NULL){
        return ;
    }
    inorder(root->left,val);
    val.push_back(root->data);
    inorder(root->right,val);
}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector<int> val;
    inorder(root,val);
    int i=0;
    int j=val.size()-1;
    while(i<j){
        int sum =val[i]+val[j];
        if(sum==target){
            return true;
        }
        if(sum>target){
            j--;}
        if(sum<target){
            i++;
        }
    }
    return false;
}