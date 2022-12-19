#include<iostream>
using namespace std;
int solve(vector<int>& cost,int n,vector<int> & dp){
    if(n==0 || n==1){
        return cost[n];
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=cost[n]+min(solve(cost,n-1,dp),solve(cost,n-2,dp));
    
}
int solve2(vector<int>& cost,int n){
    vector<int> dp(n+1,-1);
    dp[0]=cost[0];
    dp[1]=cost[1];
    for (int i = 2; i < n; i++)
    {
       dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
    }
    return dp[n];
}
int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        
        return min(solve(cost,n-1,dp),solve(cost,n-2,dp));


    }