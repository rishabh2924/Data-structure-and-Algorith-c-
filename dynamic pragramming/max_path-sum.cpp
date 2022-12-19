#include <bits/stdc++.h>

using namespace std;
// int solve(int i,int j,vector<vector<int>> &matrix,vector<vector<int>> &dp,int n,int m){
//     if(i==0){
//         return dp[i][j]=matrix[i][j];
//     }
//     if(j<0|| j>m){
//         return -1e9;
//     }
//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }
//     int up = matrix[i][j] + solve(i-1,j,matrix,dp,n,m);
//     int leftDiagonal = matrix[i][j] +solve(i-1,j-1,matrix,dp,n,m);
//     int rightDiagonal = matrix[i][j] + solve(i-1,j+1,matrix,dp,n,m);
    
//     return dp[i][j]= max(up,max(leftDiagonal,rightDiagonal));

// }
// int getMaxPathSum(vector<vector<int>> &matrix)
// {
//     int n=matrix.size();
//     int m=matrix[0].size();
//    vector<vector<int>> dp(n,vector<int>(n,-1));
//    int maxi=INT_MIN;
//    for (int j = 0; j < m; j++)
//    {
//      maxi=max(maxi,solve(n-1,j,matrix,dp,n,m));
//    }
//    return maxi;
// }

//********tabulation**************

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
     for(int j=0; j<m; j++){
        dp[0][j] = matrix[0][j];
    }
    
    
    for(int i=1; i<n; i++){
        for(int j=0;j<m;j++){
            
            int up = matrix[i][j] + dp[i-1][j];
            
            int leftDiagonal= matrix[i][j];
            if(j-1>=0) leftDiagonal += dp[i-1][j-1];
            else leftDiagonal += -1e9;
            
            int rightDiagonal = matrix[i][j];
            if(j+1<m) rightDiagonal += dp[i-1][j+1];
            else rightDiagonal += -1e9;
            
            dp[i][j] = max(up, max(leftDiagonal,rightDiagonal));
            
        }
    }
   
   int maxi=INT_MIN;
   for (int j = 0; j < m; j++)
   {
     maxi=max(maxi,dp[n-1][j]);
   }
   return maxi;
}