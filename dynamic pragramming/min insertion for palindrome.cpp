//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  int lcs(int x, int y, string s1, string s2)
    {
       vector<vector<int>> dp(x+1,vector<int>(y+1,0));
       for (int i = 0; i <=x; i++)
       {
         dp[i][0]=0;
       }
       for (int i = 0; i <= y; i++)
       {
         dp[0][i]=0;
       }
       for(int i1=1;i1<=x;i1++){
        for(int i2=1;i2<=y;i2++){
            if(s1[i1-1]==s2[i2-1]){
                dp[i1][i2]=1+dp[i1-1][i2-1];
            }
            else {
                dp[i1][i2]=max(dp[i1-1][i2],dp[i1][i2-1]);
            }
        }
       }
       return dp[x][y];
    }
    int countMin(string str){
    string B=str;
       reverse(B.begin(),B.end());
       int n=B.length();
       return n-lcs(n,n,str,B);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends