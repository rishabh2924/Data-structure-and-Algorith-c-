//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
    public:
    int lcs(int x, int y, string s1, string s2)
    {
       vector<vector<int>> dp(x+1,vector<int>(y+1,0));
       for (int i = 0; i <=x; i++)
       {
         dp[i][0]=0;
       }
       for (int i = 0; i <= y; i++)
       {
         dp[0][i]=0;
       }
       for(int i1=1;i1<=x;i1++){
        for(int i2=1;i2<=y;i2++){
            if(s1[i1-1]==s2[i2-1]){
                dp[i1][i2]=1+dp[i1-1][i2-1];
            }
            else {
                dp[i1][i2]=max(dp[i1-1][i2],dp[i1][i2-1]);
            }
        }
       }
       return dp[x][y];
    }
    
    int transfigure (string A, string B)
    {
    	int n=A.size();
        int m=B.size();
        return n+m-2*lcs(n,m,A,B);
    }
};

//{ Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}
// } Driver Code Ends