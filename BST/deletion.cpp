class Solution {
public:
    TreeNode * minval(TreeNode * root){
        while (root->left!=NULL)
        {
            root=root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        TreeNode * temp=root;
        while(temp!=NULL){
        if(temp->data=key){
            //0 child
            if(temp->left==NULL&& temp->right==NULL){
                delete temp;
                return temp;
            }
            if (temp->left==NULL && temp->right!=NULL)
            {
                Treenode* tem=temp->right;
                delete temp;
                return tem;
            }
            if (temp->right==NULL && temp->left!=NULL)
            {
                Treenode* tem=temp->left;
                delete temp;
                return tem;
            }
            if(temp->right!=NULL && temp->left!=NULL){
                int mini = minval(root->right)->data;
                temp->data=mini;
                temp->right=deleteNode(temp->right,mini);
                return temp;
            }
            

        }
        else if (temp->data>key)
        {
           temp->left= deleteNode(temp->left,key);
           return temp;
        }
        else{temp->right=  deleteNode(temp-> right,key);
        return temp;
        }
        
    }
    }
};