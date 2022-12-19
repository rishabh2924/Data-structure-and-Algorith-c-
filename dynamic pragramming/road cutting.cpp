//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int solve(int index,int n,int price[],vector<vector<int>>& dp){
    if(index==0){
        return n*price[0];
    }
    if(dp[index][n]!=-1){
        return dp[index][n];
    }
    int nottake=solve(index-1,n,price,dp);
    int take=-1e9;
    if(index+1<=n){
        take=price[index] + solve(index,n-index-1,price,dp);
    }
    return dp[index][n]=max(take,nottake);
  }
    int cutRod(int price[], int n) {
     vector<vector<int>> dp(n,vector<int>(n+1,-1));
     return solve(n-1,n,price,dp);
    }


    //////***********tabulation *************

    int cutRod(int price[], int n) {
     vector<vector<int>> dp(n,vector<int>(n+1,0));
     for(int i=0;i<=n;i++){
        dp[0][n]=n*price[0];
     }
     for(int i=1;i<n;i++){
        for(int j=0;j<=n;j++){
            int nottake=dp[i-1][j];
            int take=-1e9;
            if(i+1<=j){
                take=price[i]+dp[i][j-i-1];
            }
            dp[i][j]=max(take,nottake);
        }
     }
     return dp[n-1][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends