//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool solve(int idx,int A[],int n){
    
    
    if(idx==n-1){
        return true;
    }
    bool call;
    for (int k = 1; k <= A[idx] ; k++)
    {
         if(solve(idx+k,A,n)){
             return true;
         }
    }
    return false;
  }
    int canReach(int A[], int N) {
       return solve(0,A,N);
       
    }
 

 //------------------optimized solution -----------------
int canReach(int A[], int N){
    int pivot=N-1;
    for(int i=N-1;i>=0;i--){
        if(A[i]+i>=pivot){
            pivot=i;
        }
    }
    return pivot==0;
}





//********************another solution************************
 int canReach(int A[], int N) {
        if(N==1)
         return 1;
         
        int reachable=A[0];
        for(int i=1;i<N;i++)
        {
            if(reachable<i)
             return 0;
            if(reachable>=N)
             return 1;
            reachable=max(reachable,A[i]+i);
        }
        return 1;
    }

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends