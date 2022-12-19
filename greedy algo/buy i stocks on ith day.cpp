//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int,int>> vp(n);
        for(int i=0;i<n;i++){
            vp[i]={price[i],i+1};
        }
        sort(vp.begin(),vp.end());
        int count=0;
        for(int i=0;i<n;i++){
            if(vp[i].first*vp[i].second<=k){
                k-=vp[i].first*vp[i].second;
                count+=vp[i].second;

        }
        else{
            count+=k/(vp[i].first*vp[i].second);
            break;
        }
    }return count;}
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends