//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
       int n=A.size();
       int m=B.size();
       if(n!=m) return -1;
       int arr[256]={0};
    for(int i=0;i<A.length();i++){
        arr[A[i]]++;
        arr[B[i]]--;
    }
     for(int i=0;i<256;i++)
       {
           if(arr[i]!=0) return -1;
       }
       int i=n-1;
       int j=m-1;
       int count;
       while(i>=0 && j>=0){
        if(A[i]==B[i]){
            i--;
            j--;
        }
        else{
            i--;
            count++;
        }
       }
       return count;
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends