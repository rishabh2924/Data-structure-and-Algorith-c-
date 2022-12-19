#include <bits/stdc++.h>
using namespace std;
int solve(int i,int j1,int j2,int r,int c,vector<vector<int>>&grid,vector<vector<vector<int>>> &dp){
    if(j1<0 || j1>=c|| j2<0|| j2>=c){
        return -1e8;
    }
    if(i==r-1){
        if(j1==j2) return grid[i][j1];
        else return grid[i][j1]+ grid[i][j2];
    }
    
    if(dp[i][j1][j2]!=-1){
        return dp[i][j1][j2];
            }
    int maxi=INT_MIN;
    for (int dj1 = -1; dj1 <=1; dj1++)
    {   int ans;
        for(int dj2=-1;dj2<=1;dj2++){
            if(j1==j2){
                ans=grid[i][j1]+solve(i+1,j1+dj1,j2+dj2,r,c,grid,dp);
            }
            else {
                ans=grid[i][j1]+grid[i][j2] +solve(i+1,j1+dj1,j2+dj2,r,c,grid,dp);
            }
            maxi=max(maxi,ans);
        }
    }
    return dp[i][j1][j2]=maxi;
    
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return solve(0,0,c-1,r,c,grid,dp);
}

//***********tabulation****************
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,0)));
    for (int j1 = 0; j1 < c; j1++)
    {
       for (int j2 = 0; j2 < c; j2++)
       {
        
        if(j1==j2) dp[r-1][j1][j2] =grid[r-1][j1];
        else dp[r-1][j1][j2]=grid[r-1][j1]+grid[r-1][j2];
       }
       
    }
    
    for(int i=r-2;i>=0;i--){
        for(int j1=0;j1<c;j1++){
            for(int j2=0;j2<c;j2++){
                int maxi=INT_MIN;
                for(int dj1=-1;dj1<=1;dj1++){
                    for(int dj2=-1;dj2<=1;dj2++){
                        int ans;
                        if(j1==j2){
                            ans=grid[i][j1];
                        }
                        else ans=grid[i][j1]+grid[i][j2];
                        if ((j1 + dj1 < 0 || j1 + dj1 >= c) ||
              (j2 + dj2 < 0 || j2 + dj2 >= c))

              ans += -1e9;
            else
              ans += dp[i + 1][j1 + dj1][j2 + dj2];

            maxi = max(ans, maxi);
                    }
                }
                dp[i][j1][j2]=maxi;
            }
            
        }
    }
     return dp[0][0][c - 1];
}