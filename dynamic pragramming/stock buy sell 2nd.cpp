 #include<bits/stdc++.h>
using namespace std;
int solve(int i,int buy,vector<int>& prices,int n,vector<vector<int>> &dp){
        if(i==n) return 0;
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        if(buy){
            return dp[i][buy]=max(-prices[i]+solve(i+1,0,prices,n,dp),solve(i+1,1,prices,n,dp));
        }
        else  return dp[i][buy]=max(prices[i]+solve(i+1,1,prices,n,dp),solve(i+1,0,prices,n,dp));

    }
 int maxProfit(vector<int>& prices) {
    int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(0,1,prices,n,dp);
    }

    //*********tabulation*********
    int maxProfit(vector<int>& prices) {
    int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                
                    if(buy){
                         dp[i][buy]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                    }
                    else dp[i][buy]=max(-prices[i]+dp[i+1][1],dp[i+1][0]);
                }
            
        }
        return dp[0][1];
    }