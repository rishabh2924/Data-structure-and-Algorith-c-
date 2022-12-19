#include<bits/stdc++.h>

using namespace std;


class SpecialStack {
    // Define the data members.
    stack<int> s;
    int mini;
    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        if(s.empty()){
            s.push(data);
            mini=s.top();
        }
        else{
           
            if(data<mini){
                int val=2*data-mini;
                s.push(val);
                mini=data;
            }
            else{
                s.push(data);
            }
        }
    }

    int pop() {
        // Implement the pop() function.
        if(s.empty()){
            return -1;
        }
        
            int curr=s.top();
            if(curr>mini){
                s.pop();
                return curr;
            }
            else{
                int premin=mini;
                int val=2*mini-curr;
                mini=val;
                s.pop();
                return premin;
            }
        
    }

    int top() {
        if(s.empty()){
            return -1;
        }
        int curr=s.top();
        if(curr>mini){
return curr; }
        else return mini;
    }

    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        // Implement the getMin() function.
        if(s.empty())
            return -1;
        
        return mini;
    }  
};