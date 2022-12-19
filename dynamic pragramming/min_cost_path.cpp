//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
      int solve(vector<vector<int>>& matrix,vector<vector<int>>& dp,int i,int j,int n){
       // base case 
       // if row == n than we are out of bound than we have to return back
       if(i == n){
           return 0;
       }
       
       // checking if our column and row index is not out of bound
       if(j < 0 or j >= n){
           return -1e5;
       }
       
       // checking if we already have answer in dp or not
       if(dp[i][j] != -1){
           return dp[i][j];
       }
       
       // going left side
       int left = matrix[i][j] + solve(matrix,dp,i+1,j-1,n);
       
       // going bottom side
       int bottom = matrix[i][j] + solve(matrix,dp,i+1,j,n);
       
       // going right side
       int right = matrix[i][j] + solve(matrix,dp,i+1,j+1,n);
       
       // storing max of all three answers in dp vector after computing all path
       dp[i][j] = max(max(left,right),bottom);
       
       return dp[i][j];
       
   }
public:
   int maximumPath(int N, vector<vector<int>> matrix)
   {
       // Step 1 : finding the size of matrix
       int n = matrix.size();
       // step 2 : Declaration of Dp vector of matrix size as we assumed indexing from 0
       vector<vector<int>> dp(n,vector<int>(n,-1));
       // step 3 : declaration of maxi variable to store final answer
       int maxi = INT_MIN;
       // step 4 : running the loop from top row with different starting point and finding the minimum one
       for(int i=0;i<n;i++){
           maxi = max(maxi,solve(matrix,dp,0,i,n));
       }
       
       return maxi;
   }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends