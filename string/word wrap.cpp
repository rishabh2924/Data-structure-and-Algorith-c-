//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
int solve(int i,int rem,vector<int>nums,int k,vector<vector<int>>& dp){
    if(i==nums.size()-1){
        return 0;
    }
    if(dp[i][rem]!=0){
        return dp[i][rem];
    }
    int ans=0;
    if(nums[i]>rem){
        ans=(rem+1)*(rem+1) +solve(i+1,k-nums[i]-1,nums,k,dp);
    }
    else{
        int choice1=solve(i+1,rem-nums[i]-1,nums,k,dp);
        int choice2=(rem+1)*(rem+1)+solve(i+1,k-nums[i]-1,nums,k,dp);
        ans=min(choice1,choice2);
    }
    dp[i][rem]=ans;
    return dp[i][rem];
}
    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n =nums.size();
        vector<vector<int>> dp(n+1,vector<int>(k,-1));
        return solve(0,k,nums,k,dp);
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends