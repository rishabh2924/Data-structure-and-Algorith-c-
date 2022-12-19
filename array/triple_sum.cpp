//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A,A+n);
        int i=0;
        int j=1;
        int k=n-1;
        while(j<k){
            while(j<k){
                if(A[i]+A[j]+A[k]==X){
                    return true;
                }
                if(A[i]+A[j]+A[k]<X){
                    j++;
                }
                if(A[i]+A[j]+A[k]>X){
                    k--;
                }
            }
            i++;
            j=i+1;
            k=n-1;
        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends