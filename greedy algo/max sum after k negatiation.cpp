//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
         priority_queue<int, vector<int>, greater <int> > pq;
        long long sum = 0;

        for(int i = 0; i < n; i++){
            pq.push(a[i]); 
            sum += a[i];
        }
        
        while(k--){
            int ele = pq.top();
            pq.pop();
            sum -= 2*ele;
            pq.push(-ele);
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}
// } Driver Code Ends