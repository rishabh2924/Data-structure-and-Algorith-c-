#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> count(n,1);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]&& dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    count[i]=count[j];
                }
                else if(nums[i]>nums[j]&& dp[j]+1==dp[i]){
                    count[i]+=count[j];
                }

            }
            maxi=max(maxi,dp[i]);
        }
        int num=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                num+=count[i];
            }
        }
        return num;
    }
};