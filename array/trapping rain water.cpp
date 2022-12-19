//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
       long long count=0;
       int l=0,r=n-1;
       int maxl=0,maxr=0;
       while (l<=r)
       {
        if(arr[l]<=arr[r]){
            if(arr[l]<maxl){
                count +=maxl-arr[l];
            }
            else maxl=arr[l];
        }
        else{
            if (arr[r]<maxr)
            {
                count+= maxr-arr[r];
            }
            else maxr=arr[r];
            
        }
       }
       return count;

    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends