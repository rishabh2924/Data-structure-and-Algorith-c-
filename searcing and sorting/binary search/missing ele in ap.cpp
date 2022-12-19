//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMissing(int arr[], int n) {
        if(n == 2)
            return (arr[0]+arr[1])/2;
        int d = min(arr[1]-arr[0],arr[2]-arr[1]);
        int left=0, right=n-1, mid, ans;
        while(left <= right) {
            mid = left+(right-left)/2;
            int term = arr[0]+(mid)*d;
            if(arr[mid] != term) {
                ans = mid;
                right = mid-1;
            }
            else
                left = mid+1;
        }
        return arr[0]+(ans*d);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMissing(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends