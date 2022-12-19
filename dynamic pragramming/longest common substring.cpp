//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
       for (int i = 0; i <=n; i++)
       {
         dp[i][0]=0;
       }
       for (int i = 0; i <= m; i++)
       {
         dp[0][i]=0;
       }
       int ans=0;
       for(int i1=1;i1<=n;i1++){
        for(int i2=1;i2<=m;i2++){
            if(S1[i1-1]==S2[i2-1]){
                dp[i1][i2]=1+dp[i1-1][i2-1];
                ans=max(ans,dp[i1][i2]);
            }
            else {
                dp[i1][i2]=0;
            }
        }
       }
       return ans;
    }
    
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends