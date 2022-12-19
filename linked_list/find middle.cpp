#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head->next==NULL){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast =head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            head=slow;
            fast=fast->next->next;
        }
        return head;
    }
};