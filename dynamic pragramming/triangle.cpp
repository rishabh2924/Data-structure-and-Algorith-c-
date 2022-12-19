
// int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp,int n){
//     if(i==n-1){
//         return dp[i][j]=triangle[n-1][j];
//     }
//     if(dp[i][j]==-1){
//         return dp[i][j];
//     }
//     int down=triangle[i][j] +solve(i+1,j,triangle,dp,n);
//     int diagonal=triangle[i][j]+ solve(i+1,j+1,triangle,dp,n);
//     return dp[i][j]=min(down,diagonal);
// }
// int minimumPathSum(vector<vector<int>>& triangle, int n){
// 	vector<vector<int>> dp(n,vector<int>(n,-1));
//     return solve(0,0,triangle,dp,n);
// }

//********tabulation***************
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int> >dp(n,vector<int>(n,0));
    for (int j = 0; j < n; j++)
    {
        dp[n-1][j]=triangle[-1][j];
    }
    for (int i = n-2;i>=0; i--)
    {
        for (int j = i; j>=0; j--)
        {
           int down = triangle[i][j]+dp[i+1][j];
            int diagonal = triangle[i][j]+dp[i+1][j+1];
            
            dp[i][j] = min(down, diagonal);
        }
        
    }
    
    return dp[0][0];

}
