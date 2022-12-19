//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        int ans=0;
       unordered_map<char,int> num;
       num['I'] = 1;
       num['V'] = 5;
       num['X'] = 10;
       num['L'] = 50;
       num['C'] = 100;
       num['D'] = 500;
       num['M'] = 1000;
       for(int i=0;i<str.size()-1;i++){
        char c=str[i];
        char cpp=str[i+1];
        if(num[c]>=num[cpp]){
            ans += num[c];
        }
        else{
            ans -=num[c];
        }
       }
       ans+= num[str[str.size()-1]];
       return ans;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends