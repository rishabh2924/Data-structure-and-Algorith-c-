#include <bits/stdc++.h> 
class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};
Node *merge(Node* head1, Node* head2){
    Node*temp1=head1;
    while(head1->child != NULL && head2 != NULL) {
        if(head1->child->data <= head2->data) {
            head1 = head1->child;
        }
        else {
            Node* temp = head2->child; 
            head2->child = head1->child;
            head1->child = head2;
            head1 = head2;
            head2 = temp;
        }
    }
    if(head1->child == NULL) {
        head1->child = head2;
    }
    return temp1;}
Node* flattenLinkedList(Node* head) 
{
      if(head==NULL || head->next==NULL) return head;
	Node*next=head->next;
    
    Node*down=head;
    
    Node*chead=flattenLinkedList(next);
    Node*ans=merge(down,chead);
    return ans;
}
