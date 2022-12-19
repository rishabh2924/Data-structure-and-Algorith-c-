#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> res;
    unordered_map<string,int> mapping;
    int invalid(string s){
        stack<char> st;
        int i=0;
        int n=s.size();
        while(i<n){
            if(s[i]=='('){
                st.push('(');
            }
            else if(s[i]==')'){
                if(st.size()>0 && st.top()=='('){
                    st.pop();
                }
                else
                    st.push(')');
                
            }
            i++;
        }
        return st.size();
    }
    void solve(string s,int minvalue){
        if(mapping[s]!=0){
            return ;
        }
        if(mapping[s]==0){
            mapping[s]++;
        }
        if(minvalue==0){
           if(invalid(s)==0){
            res.push_back(s);
           }
           return ;
        }
        for(int i=0;i<s.size();i++){
            string left=s.substr(0,i);
            string right=s.substr(i+1);
            solve(left+right,minvalue-1);
        }
        return ;
    }
    vector<string> removeInvalidParentheses(string s) {
        solve(s,invalid(s));
        return res;
    }
};