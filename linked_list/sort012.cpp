#include <bits/stdc++.h> 

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };


void insertattail(Node *&tail,Node*&curr){
    tail->next=curr;
    tail=curr;
}
Node* sortList(Node *head)
{
    Node *zerohead=new Node(-1);
    Node *onehead=new Node(-1);
    Node *twohead=new Node(-1);
    Node *zerotail=zerohead;
    Node *onetail=onehead;
    Node *twotail=twohead;
    Node* curr=head;
    while(curr!=NULL){
        if(curr->data==0){
            insertattail(zerotail,curr);
        }
        else if(curr->data==1){
            insertattail(onetail,curr);
        }
        else{
            insertattail(twotail,curr);
        }
        curr=curr->next;
    }
//merge these lists
    if(onehead==NULL){
        zerotail->next=twohead->next;
    }
    else {zerotail->next=onehead->next;
    onetail->next=twohead->next;}
    twotail->next=NULL;
    //setup head
    head=zerohead->next;
    delete(zerohead);
     delete(onehead);
     delete(twohead);
    return head;
}