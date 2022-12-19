pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int suc=-1;
    int pred=-1;
    while(root->data!=key){
        if(key>root->data){
            pred=root->data;
            root=root->right;
        }
        else{
            suc=root->data;
            root=root->left;
        }
    }
    BinaryTreeNode<int>* lefttree=root->left;
    BinaryTreeNode<int>* righttree=root->right;
    while(lefttree!=NULL){
        pred=lefttree->data;
        lefttree=lefttree->right;
    }
     while(righttree!=NULL){
        suc=righttree->data;
        righttree=righttree->left;
    }
    return {pred,suc};
    
}