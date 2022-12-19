//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
    // int mod=1e9+7;
	// int solve(int idx,int arr[],int sum,vector<vector<int>> &dp){
       
    //     if(idx==0){
    //         if(sum==0 && arr[0]==0) return 2;
    //         if(sum==0 || sum==arr[0])return 1;
    //         return 0;}
    //     if(dp[idx][sum]!=-1) return dp[idx][sum]%mod;
    //     int nottake= solve(idx-1,arr,sum,dp);
    //     int take=0;
    //     if(arr[idx]<=sum)
    //         take=solve(idx-1,arr,sum-arr[idx],dp)%mod;
    //     return dp[idx][sum]=(take+nottake)%mod;

    // }
	// int perfectSum(int arr[], int n, int sum)
	// {
         
    //     vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    //     int ans=solve(n-1,arr,sum,dp);
    //     return ans;
	// }
	  



      int perfectSum(int arr[], int n, int sum)
	{
         
        long long int mod=1e9+7;
        long long int dp[n+1][sum+1];
        int zero=0;
        for(int i=0;i<n;i++) if(!arr[i]) zero++;
        
        for(int i=0;i<=sum;i++) dp[0][i]=0;
        for(int i=0;i<=n;i++) dp[i][0]=1;
        
        for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=sum;j++)
	        {
	            if(j>=arr[i-1]) dp[i][j]=(dp[i-1][j]%mod + dp[i-1][j-arr[i-1]]%mod)%mod;
	            else dp[i][j]=dp[i-1][j];
	        }
	    }
	    return dp[n][sum]+pow(2,zero)-1;
        
	}
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends