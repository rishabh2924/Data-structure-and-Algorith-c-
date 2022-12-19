//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        //Write your code here
         int h=1,v=1;
        int i=M-2;
        int j=N-2;
        int cost=0;
        sort(X.begin(),X.end());
        sort(Y.begin(),Y.end());
        while(i>=0 && j>=0){
            if(X[i]>=Y[j]){
                cost+=X[i]*h;
                v++;
                i--;
            }
            else{
                cost+=Y[j]*v;
                h++;
                j--;
            }
        }
        while(j>=0){
            cost+=Y[j]*v;
            j--;
        }
        while(i>=0){
            cost+=X[i]*h;
            i--;
        }
        return cost;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    vector<int>X(m - 1), Y(n - 1);
	    for(int i = 0; i < m - 1; i++){
	        cin >> X[i];
	    }
	    for(int i = 0; i < n - 1; i++){
	        cin >> Y[i];
	    }
	    Solution ob;
	    int ans = ob.minimumCostOfBreaking(X, Y, m, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends