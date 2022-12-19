//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long long solve(int index,int sum,int coins[], vector<vector<long long>>& dp){
    if(index==0){
        if(sum%coins[0]==0) return sum/coins[0];
        else return 0;
    }
    if(dp[index][sum]!=-1){
        return dp[index][sum];
    }
    long long nottaken=solve(index-1,sum,coins,dp);
    long long taken =0;
    if(coins[index]<=sum){
        taken=solve(index,sum-coins[index],coins,dp);
    }
    return dp[index][sum]=taken + nottaken;
  }
    long long int count(int coins[], int N, int sum) {

        vector<vector<long long>> dp(N,vector<long long>(sum+1,-1));
        return solve(N-1,sum,coins,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends