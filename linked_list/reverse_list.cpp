#include<iostream>
#include <bits/stdc++.h> 
using namespace std;
template <typename T>
class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };


LinkedListNode<int> *reverse1(LinkedListNode<int> *&head){
    if(head==NULL||head->next==NULL){
        return head;}
    LinkedListNode<int> *littlehead=reverse1(head->next);
    head->next->next=head;
    head->next=NULL;
    return littlehead;
} 
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    return reverse1(head);
}