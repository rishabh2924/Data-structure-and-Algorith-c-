//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	void solve(int num,int target,vector<int>temp,vector<vector<int>> &res){
	    if(num<=0){
	        return;
	    }
	    if(target==0){
	        res.push_back(temp);
	    }
	    if(target<=0){
	        return ;
	    }
	    temp.push_back(num);
	    solve(num,target-num,temp,res);
	    temp.pop_back();
	    solve(num-1,target,temp,res);
	}
    vector<vector<int>> UniquePartitions(int n) {
        // Code here
        vector<vector<int>> res;
        vector<int> temp;
        
        solve(n,n,temp,res);
        return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends