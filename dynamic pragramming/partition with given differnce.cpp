#include <bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int solve(int n,vector<int> &arr,int k){
    vector<vector<int>> dp(n, vector<int>(k+1, 0));
    if(arr[0]==0) dp[0][0]=2;
    else dp[0][0]=1;
    if(arr[0]!=0 && arr[0]<=k) dp[0][arr[0]]=1;
    for (int i = 1; i < n; i++)
    {
       for (int sum = 0; sum <=k; sum++)
       {
        int nottake=dp[i-1][sum];
        int take=0;
        if(arr[i]<=sum){
            take=dp[i-1][sum-arr[i]];
        }
        dp[i][sum]=(take+nottake)%mod;
       }
       
    }
    return dp[n-1][k];

}
int countPartitions(int n, int d, vector<int> &arr) {
    int totalsum=0;
    for(int i=0;i<arr.size();i++){
        totalsum+=arr[i];
    }
    if((totalsum-d)<0 || (totalsum-d)%2){
        return 0;
    }
    return solve(n,arr,(totalsum-d)/2);
}
