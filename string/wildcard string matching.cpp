//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool match(string wild, string pattern)
    {
        int n=wild.length();
        int m=pattern.length();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,0));
        dp[0][0]=1;
        for(int j=1;j<=m;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++){
            bool flag =1;
            for (int a = 1; a<=i; a++)
            {
                if(wild[a-1]!='*'){
                    flag =0;
                    break;
                }
            }
            dp[i][0]=flag;
        }
        for (int i = 1; i <= n; i++)
        {
            for(int j=1;j<=m;j++){
                if(wild[i-1]==pattern[j-1]|| wild[i-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(wild[i-1]=='*'){
                    dp[i][j]=dp[i-1][j] || dp[i][j-1];
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        
        return dp[n][m];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends