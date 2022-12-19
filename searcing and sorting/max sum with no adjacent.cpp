//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
   int solve(int index,int arr[],vector<int> &dp){
        if(index==0){
            return arr[0];
        }
        if(index<0){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int take= arr[index]+solve(index-2,arr,dp);
        int notTake=solve(index-1,arr,dp);
        return dp[index]=max(take,notTake);
    }
	// calculate the maximum sum with out adjacent
	int FindMaxSum(int arr[], int n) {
        vector<int> dp(n+1,-1);
	    return solve(n-1,arr,dp);
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends