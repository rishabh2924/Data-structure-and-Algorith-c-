//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
     int dp[1101];
     unordered_set<string>st;
   int solve(string &s,int index)
   {
       if(index==s.size())return 1;
       string temp;
       if(dp[index]!=-1)
           return dp[index];
       for(int j=index;j<s.size();j++)
       {
        temp +=s[j];
           if(st.find(temp)!=st.end())
               if(solve(s,j+1))
                   return dp[index]=1;
       }
       return dp[index]=0;
   }
   int wordBreak(string s, vector<string> &wordDict) {
       //code here
        memset(dp,-1,sizeof(dp));
       for(auto x:wordDict)
       {
           st.insert(x);
       }
      return solve(s,0);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends