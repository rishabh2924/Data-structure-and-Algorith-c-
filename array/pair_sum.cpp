//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
    //      sort(arr,arr+n);
    //     int i=0;
    //     int j=n-1;
    //     int count=0;
    //     while (i<j)
    //     {
    //         if(arr[i]+arr[j]==k){
    //             count++;
    //             //for same elements
    //             int m=i+1;
    //             while(m<j &&arr[i]==arr[m] ){
    //                 count++;
    //                 m++;
    //             }
    //             j--;
    //         }
    //         else if(arr[i]+arr[j]>k){
    //             j--;
    //         }
    //         else if(arr[i]+arr[j]<k){
    //             i++;
    //         }
            
    //     }
    //    return count;


    //-----------------solution with hashing----------------

    unordered_map<int,int> m;
    int count=0;
    for (int i = 0; i < n; i++)
    {
        if(m.find(k-arr[i]) !=m.end()){
            count+= m[k-arr[i]];
        }
        m[arr[i]]++;
    }
    return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends