#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;
class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int x=s1.length();
        int y =s2.length();
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
       int i=x;
       int j=y;
       string ans="";
       while(i>0&& j>0){
        if(s1[i-1]==s2[j-1]){
            ans+=s1[i-1];
            x--;y--;
        }
        else if(dp[i-1][j]>dp[i][j]){
            ans+=s1[i-1];
            i--;
        }
        else {
            ans+=s2[j-1];
            j--;
        }
       }
       while(i>0){
        ans+=s1[i-1];
        i--; 
       }
       while(j>0){
        ans+=s2[j-1];
        j--;
       }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};