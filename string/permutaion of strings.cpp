//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    void solve(int index,string s,vector<string> &ans){
            if(index==s.size()){
                ans.push_back(s);
                return ;
            }
            for (int j = index; j < s.size(); j++)
            {
                if(j>index&& s[j]==s[j-1]) continue;
                swap(s[j],s[index]);
                solve(index+1,s,ans);
                swap(s[j],s[index]);
            }
            
    }
		vector<string>find_permutation(string S)
		{
		    vector<string> ans;
            sort(S.begin(),S.end());
           
            solve(0,S,ans);
            return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends