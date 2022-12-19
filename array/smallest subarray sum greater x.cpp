//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        int i=0,j=0,mini=0,sum=0;
        
        while (i<n)
        {
           if(sum<=x){
            sum+=arr[i];
            i++;
           }
           else{
            mini=min(mini,i-j+1);
            sum-=arr[j];
            j--;
           }
        }
        return mini;   
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends