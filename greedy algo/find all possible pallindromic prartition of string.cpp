//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool isPalindrome(string s){
      int i = 0, j = s.size()-1;
      while(i<=j){
          if(s[i]==s[j]){
              i++, j--; 
              continue;
          }
          return false;
      }
      return true;
  }
  void solve(string s, vector<vector<string>> &res,int index,vector<string> &copy){
    if(index>=s.length()){
        res.push_back(copy);
        return;
    }
    string str="";
    for(int j=index;j<s.length();j++){
        str+=s[j];
        if(isPalindrome(str)){
            copy.push_back(str);
            solve(s,res,j+1,copy);
            copy.pop_back();
        }

    }
  }
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<vector<string>>res;
        //string temp = "";
        vector<string> copy;
        solve(S,res,0,copy);
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends