#include <bits/stdc++.h> 
class Solution
{
    public:
    void insertattail( Node*& head,  Node* &tail,int val){
        Node* temp=new Node(val);
        if(head==NULL){
            head=temp;
            tail=temp;
            return;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    Node *copyList(Node *head)
    {
        Node*chead=NULL;
        Node *ctail=NULL;
        Node*temp=head;
        while(temp!=NULL){
            insertattail(chead,ctail,temp->data);
            temp=temp->next;
        }
    Node *original=head;
    Node *clone=chead;
    while(original!=NULL && clone!=NULL){
        Node*next=original->next;
        original->next=clone;
        original=next;
        
        next=clone->next;
        clone->next=original;
        clone=next;
        
    }
    //third step
    temp=head;
    while(temp!=NULL){
        if(temp->next!=NULL){
            temp->next->arb=temp->arb?temp->arb->next:temp->arb;
        }
        temp=temp->next->next;
    }
    //fouth
    original=head;
    clone=chead;
    while(original!=NULL && clone!=NULL){
        original->next=clone->next;
        original=original->next;
        if(original!=NULL){
            clone->next=original->next;
            
            
        }
        clone=clone->next;
        
    }
    return chead;
    }
    
};