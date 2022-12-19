/*Given an array Arr of size N such that each element is from the range 0 to 9.
 Find the minimum possible sum of two numbers formed using the elements of the array.
  All digits in the given array must be used to form the two numbers.*/
  //{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        sort(arr,arr+n);
        string res="";
        int carry=0;
        int i=n-1;
        while(i>=0){
            int ans=arr[i]+carry;
            if((i-1)>=0){
                ans+=arr[i-1];
            }
            int s=ans%10;
            carry=ans/10;
            res+=to_string(s);
        }
        if(carry){
            res.push_back('1');
        }
         while(!res.empty() and res.back()=='0')//if 0 exist in front
          res.pop_back();
        reverse(res.begin(),res.end());
        return res;
        
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
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends