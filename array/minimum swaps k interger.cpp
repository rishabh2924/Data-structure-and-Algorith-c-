//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
    //    int count =0;
    //    for (int i = 0; i < n; i++)
    //    {
    //     if(arr[i]<=k) count++;
    //    }
    //    //i tracking last of window and j is tracking starting of window
       
    //    int i=0,j=0,mini=INT_MAX,swaps=0;
    //    while(i<n){
    //     if(arr[i]>k) swaps++;
    //     if(i-j+1<=count) j++;
    //     else{
    //         mini=min(mini,swaps);
    //         if(arr[i]>k) swap--;
    //         i++;
    //         j++;
    //     } 
    //    }
    //    return mini;

    int count =0;
       for (int i = 0; i < n; i++)
       {
        if(arr[i]<=k) count++;
       }
       int i=0,j=count,ans=INT_MAX,swp=0;
       for ( i = 0; i < count; i++)
       {
          if(arr[i]>k) swp++;
          
       }
       while(j<n){
        ans=min(swp,ans);
        if(arr[j]>k) swp++;
        if(arr[i]>k) swp--;

        i++;
        j++;
       }
       return ans;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends