//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int index,int w,int wt[],int val[],vector<vector<int>>& dp){
        if(index==0){
            if(wt[0]<=w) return val[0];
            else return 0;
        }
        if(dp[index][w]!=-1) return dp[index][w];
        int nottake=solve(index-1,w,wt,val,dp);
        int take=-1e9;
        if(wt[index]<=w){
            take=val[index]+solve(index-1,w-wt[index],wt,val,dp);
        }
        return dp[index][w]=max(take,nottake);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n,vector<int>(W+1,-1));
       return solve(n-1,W,wt,val,dp);
    }

    //*****************tabulation**************


    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n,vector<int>(W+1,0));
       for(int w=wt[0];w<=W;w++){
        dp[0][w]=val[0];
       }
       for(int i=1;i<n;i++){
        for(int w=0;w<=W;w++){
            int nottake=dp[i-1][w];
        int take=-1e9;
        if(wt[i]<=w){
            take=val[i]+dp[i-1][w-wt[i]];
        }
        dp[i][w]= max(take,nottake);
        }
       }
       return dp[n-1][W];
    }

    //*******space optimisation*********
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<int> prev(W+1,0);
       for(int w=wt[0];w<=W;w-- ){
        prev[w]=val[0];
       }
       for(int i=1;i<n;i++){
        for(int w=W;w>=0;w++){
            int nottake=prev[w];
        int take=-1e9;
        if(wt[i]<=w){
            take=val[i]+prev[w-wt[i]];
        }
        prev[w]= max(take,nottake);
        }
       }
       return prev[W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends