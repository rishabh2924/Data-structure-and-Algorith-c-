//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
  public:
  void inorder(vector<int>&A, int n,int i,vector<int>& vec){
	if(i>=n){
		return ;
	}
	inorder(A,n,2*i+1,vec);
	vec.push_back(A[i]);
	inorder(A,n,2*i+2,vec);
  }
  int swaps(vector<int> &vec,int n){
	unordered_map<int,int> map;
	for(int i=0;i<n;i++){
		map[vec[i]]=i;
	}
	sort(vec.begin(),vec.end());
	int i=0;
	int count =0;
	while(i<n){
		if(map[vec[i]]!=i){
			count++;
			swap(vec[i],vec[map[vec[i]]]);
			continue;
		}
		i++;
	}
	return count;
  }
    int minSwaps(vector<int>&A, int n){
       vector<int> vec;
	   inorder(A,n,0,vec);
	   return swaps(vec,n);
	
    }
    
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>A(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> A[i];
	    }
	    Solution ob;
	    int ans = ob.minSwaps(A, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends