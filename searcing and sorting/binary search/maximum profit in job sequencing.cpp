#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool cmp(vector<int>a,vector<int>b){
        return a[1]<b[1];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>> v(n);
        for(int i=0;i<n;i++){
            int x=startTime[i];
            int y=endTime[i];
            int z=profit[i];
            v[i]={x,y,z};
        }
        sort(v.begin(),v.end(),cmp);
        int dp[n];
        dp[0]=v[0][2];
        for(int i=1;i<n;i++){
            int include=v[i][2];
            int last=-1;
            int low=0;
            int high=i-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(v[mid][1]<=v[i][0]){
                    last=mid;
                    low=mid+1;
                }
                else high=mid-1;
            }
            if(last!=-1) include+=dp[last];
            int exc=dp[i-1];
            dp[i]=max(include,exc);
        }
        return dp[n-1];
    }
};