//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool solve(int i,int target,vector<int>arr,vector<vector<int>> &dp){
        if(target==0){
            return true;
        }
        if(i==0){
            return arr[0]==target;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        bool nottake=solve(i-1,target,arr,dp);
        bool take=false;
        if(target>=arr[i])
           take= solve(i-1,target-arr[i],arr,dp);
        return dp[i][target]=nottake |take;
    }
    bool isSubsetSum(vector<int>arr, int sum){
       int n=arr.size();
       vector<vector<int>> dp(n,vector<int>(sum+1,-1));

       solve(n-1,sum,arr,dp);
    }

    //*********tabulation************
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
       
    
    for(int i=0; i<n; i++){
        dp[i][0] = true;
    }
    
    if(arr[0]<=sum)
        dp[0][arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=sum; target++){
            
            bool notTaken = dp[ind-1][target];
    
            bool taken = false;
                if(arr[ind]<=target)
                    taken = dp[ind-1][target-arr[ind]];
        
            dp[ind][target]= notTaken||taken;
        }
    }
    
    return dp[n-1][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends