#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
    //    if (n == 0) return "";
    // string res = "1";
    // while (--n) {
    //     string cur = "";
    //     for (int i = 0; i < res.size(); i++) {
    //         int count = 1;
    //          while ((i + 1 < res.size()) && (res[i] == res[i + 1])){
    //             count++;    
    //             i++;
    //         }
    //         cur += to_string(count) + res[i];
    //     }
    //     res = cur;
    // }
    // return res;
     
     // *******************here I solved with O(n^2);
     if(n==0) return "";
     string res="1";
     int count ;
     char c;
     while(n>1){
        string temp="";
        c=res[0];
        count =1;
        for(int i=1;i<res.size();i++){
            if(res[i]==res[i-1]){
                count ++;
            }else{
                temp +=to_string(count);
                temp.push_back(c);
                c=res[i];
                count =1;
            }
        }
        temp +=to_string(count);
        temp.push_back(c);
        res=temp;
        n--;
     }
        return res;
    }
};