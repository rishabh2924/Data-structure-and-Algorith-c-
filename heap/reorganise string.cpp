//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> count;
        int n= s.length();
        for(int i=0;i<n;i++){
            count[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        string res="";
        for(auto m:count){
            pq.push({m.first,m.second});
        }
        while(pq.size()>1){
            pair<int,char>  first_most=pq.top();
            pq.pop();
            pair<int,char>  second_most=pq.top();
            pq.pop();
            res +=first_most.second;
            res+= second_most.second;
            first_most.first--;
            second_most.first--;
            if(first_most.first>0){
                pq.push(first_most);
            }
            if(second_most.first>0){
                pq.push(second_most);
            } 
        }
        if(!pq.empty()){
            if(pq.top().first > 1)
                return "";
            
            else
                res+=pq.top().second;
        }
        
        return res;

    }
};