#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int solve(int i,int j,vector<int>& cuts,vector<vector<int>>&dp){
    if(i>j) return 0;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mini=INT_MAX;
    int steps;
    for(int k=i;k<=j;k++){
        steps=cuts[j+1]-cuts[i-1]+solve(i,k-1,cuts,dp)+solve(k+1,j,cuts,dp);
        mini=min(steps,mini);
    }
    return dp[i][j]=mini;
}
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        return solve(1,c,cuts,dp);
    }

    //*********tabulation***********

    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        vector<vector<int>> dp(c+2,vector<int>(c+2,0));
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        for(int i=c;i>=1;i--){
            for(int j=i;j<=c;j++){
                int mini=INT_MAX;
    int steps;
    for(int k=i;k<=j;k++){
        steps=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
        mini=min(steps,mini);
    }
    dp[i][j]=mini;
            }
        }
        return dp[1][c];
    }
}; 