//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

// Function to find maximum product subarray
long long maxProduct(vector<int> arr, int n) {
        long long curproduct=1,maxproduct=INT_MIN;
        for(int i=0;i<n;i++){
            
            curproduct=curproduct*arr[i];
            maxproduct=max(maxproduct,curproduct);
            if(curproduct==0){
                curproduct=1;
            }
            
        }
        curproduct=1;
        for(int i=n-1;i>=0;i--){
            
            curproduct=curproduct*arr[i];
            maxproduct=max(maxproduct,curproduct);
            if(curproduct==0){
                curproduct=1;
            }
            
        }
        return maxproduct;
    // code here
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends