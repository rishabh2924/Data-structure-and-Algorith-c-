//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int solve(int i,int prev,int a[],int n,vector<vector<int>> &dp){
        if(i==n){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int len=solve(i+1,prev,a,n,dp);
        if(prev==-1 || a[i]>a[prev]){
            len=max(len,1+solve(i+1,i,a,n,dp));
        }
        return dp[i][prev+1]=len;
    }
    int longestSubsequence(int n, int a[])
    {
      vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
      return solve(0,-1,a,n,dp);
    }

    //*********tabulation*************
int longestSubsequence(int n, int a[])
    {
      vector<vector<int>> dp(n+1,vector<int>(n+1,0));
      for(int i=n-1;i>=0;i--){
        for(int prev=i-1;prev>=0;prev--){
            int len=dp[i+1][prev];
        if(prev==-1 || a[i]>a[prev]){
            len=max(len,1+dp[i+1][prev]);
        }
        dp[i+1][prev]=len;
        }
      }
    return dp[0][0];
    }
    


};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends