//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
     bool solve(int i,int target,int sum,int n,int arr[], vector<vector<int>> &dp){
        if(i>=n|| sum>target){
            return 0;
        }
        if(target==sum){
            return 1;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        bool inc=solve(i+1,target,sum+arr[i],n,arr,dp);
        bool not_inc=solve(i+1,target,sum,n,arr,dp);
        return dp[i][sum]= inc|| not_inc;
    }
    int equalPartition(int N, int arr[])
    {
        // code here
       
        int sum =0;
        for(int i=0;i<N;i++){
            sum +=arr[i];
        }
         vector<vector<int>> dp(N,vector<int>(sum/2,-1));
        if(sum%2!=0)
         return 0;
        return  solve(0,sum/2,0,N,arr,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends