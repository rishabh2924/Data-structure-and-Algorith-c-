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


void inorder(TreeNode<int>* root, vector<int>& val){
    if(root==NULL){
        return ;
    }
    inorder(root->left,val);
    val.push_back(root->data);
    inorder(root->right,val);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
     vector<int> val;
    inorder(root,val);
    int n=val.size();
    TreeNode<int>* newnode= new TreeNode<int>(val[0]);
    TreeNode<int>* curr=newnode;
    for(int i=1;i<n;i++){
        TreeNode<int>* temp=new TreeNode<int>(val[i]);
        curr->left=NULL;
        curr->right=temp;
        curr=temp;
    }
    curr->left=NULL;
    curr->right=NULL;
    return newnode;
    
}