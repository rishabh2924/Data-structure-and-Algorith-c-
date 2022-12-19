//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
    int solve(int index,int target,int coins[],vector<vector<int>>& dp){
        //base case
        if(index==0){
            if(coins[0]%target==0) return target/coins[0];
            else return 1e9;
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        int nottake=0+solve(index-1,target,coins,dp);
        int take=1e9;
        if(coins[index]<=target){
            take= 1+solve(index,target-coins[index],coins,dp);
        }
        return dp[index][target]=min(take,nottake);
    }
	int minCoins(int coins[], int M, int V) 
	{ 
	   vector<vector<int>> dp(M+1,vector<int>(V+1,-1));
       int ans=solve(M-1,V,coins,dp);
       if(ans>=1e9){
        return -1;
       }
       return ans;
	} 


    //***********tabulation method***********************
int minCoins(int coins[], int M, int V) 
	{ 
	   vector<vector<int>> dp(M+1,vector<int>(V+1,0));
       for(int t=0;t<=V;t++){
        if(t%coins[0]==0) dp[0][t]=t/coins[0];
        else dp[0][t]=1e9;
       }
       for (int i = 1; i < M; i++)
       {
        for(int t=0;t<=V;t++){
            int nottake=dp[i-1][t];
            int take=1e9;
            if(coins[i]<=t){
                take=1+dp[i][t-coins[i]];
            }
            dp[i][t]=min(take,nottake);
        }
       }
      
       int ans=dp[M-1][V];
       if(ans>=1e9){
        return -1;
       }
       return ans;
	} 

	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends