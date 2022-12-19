//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:

    long long int findMaxProduct(vector<int>&a, int n){
        //Write your code here  
        int mod=10e7+7;
        int count_zero=0;
        int count_neg=0;
        long long prod=1;
        int max_neg=INT_MIN;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                count_zero++;
                continue;
            }
            else if(a[i]<0){
                count_neg++;
                max_neg=max(max_neg,a[i]);
        }
        prod=(prod*a[i])%mod ;}
        if(count_neg==1 && count_zero+count_neg==n){
            return 0;
        }
        if(count_neg&1) prod=prod/max_neg;
        return prod;

    }                                           
};                                        



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends