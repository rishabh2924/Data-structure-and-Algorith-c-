#include<bits/stdc++.h>
using namespace std;
// int solve(int idx,vector<int> &heights,vector<int>&dp){
//     if(idx==0){
//         return 0;
//     }
//     if(dp[idx]!=-1){
//         return dp[idx];
//     }
//     int left=solve(idx-1,heights,dp) + abs(heights[idx]-heights[idx-1]);
//     int right=INT_MAX;
//     if(idx>1){
//     right=solve(idx-2,heights,dp) + abs(heights[idx]-heights[idx-2]);
//     }
//     return dp[idx]=min(left,right);
// }


//.......tabular...method....

// int solve(int n,vector<int>&heights){
//     vector<int> dp(n,-1);
//     dp[0]=0;
//     for (int i = 1; i < n; i++)
//     {
//         int left=dp[i-1]+abs(heights[i]-heights[i-1]);
//         int right=INT_MAX;
//         if(i>1){
//             right=dp[i-2] + abs(heights[i]-heights[i-2]);
//         }
//         dp[i]=min(left,right);
//     }
//     return dp[n-1];
// }
int solve(int n,vector<int>&heights){
    vector<int> dp(n,-1);
    int prev1=0;
    int prev2=0;
    for (int i = 1; i < n; i++)
    {
        int left=prev1+abs(heights[i]-heights[i-1]);
        int right=INT_MAX;
        if(i>1){
            right=prev2 + abs(heights[i]-heights[i-2]);
        }
        int curr=min(left,right);
        prev1=curr;
        prev2=prev1;
    }
    return prev1;
}
int frogJump(int n, vector<int> &heights)
{
    
    return solve(n,heights);
}