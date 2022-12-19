//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	   int totalsum=0;
       for(int i=0;i<n;i++){
        totalsum=totalsum+arr[i];
       } 
       
       vector<vector<bool>> dp(n,vector<bool>(totalsum+1,0));
       for(int j=0;j<n;j++){
        dp[j][0]=true;
       }
       if(arr[0]<=totalsum){dp[0][arr[0]]=true;}
       for (int  i = 1; i < n; i++)
       {
            for(int target =1;target<=totalsum;target++){
                bool notTaken = dp[i-1][target];
    
            bool taken = false;
                if(arr[i]<=target)
                    taken = dp[i-1][target-arr[i]];
        
            dp[i][target]= notTaken||taken;
            }
       }
       int mini=1e9;
       for (int i = 0; i <=totalsum; i++)
       {
        if(dp[n-1][i]==true){
            mini=min(mini,abs(totalsum-2*i));
        }
       }
       return mini;

	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends