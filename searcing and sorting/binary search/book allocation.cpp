//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool ispossible(int A[], int N, int M,int mid){
        int num=0;
        int count=1;
        for(int i=0;i<N;i++){
            if(A[i]>mid) return false;
            if(num+A[i]<=mid){
                num+=A[i];
            }
            else{
                count++;
                num=A[i];
            }
        }
        if(count<=M){
            return true;
        }
        return false;
    }
    int findPages(int A[], int N, int M) 
    {
       if(N<M){
            return -1;
        }
       int totalsum=0;
      
       for(int i=0;i<N;i++){
        totalsum+=A[i];
           
       }
       int s=0;
       int e=totalsum;
       int ans=-1;
       while(s<=e){
        int mid=s+(e-s)/2;
        if(ispossible(A,N,M,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends