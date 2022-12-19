#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
        int solve(vector<int> &arr) {
        int n=arr.size();
        int prev1=arr[0];
        int prev2=0;
	    
        for(int i=1;i<n;i++){
            int take=arr[i];
            if(i>1) take+= prev2;
            int notTake=prev1;
            int curr=max(take,notTake);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
	
	}
    int rob(vector<int>& nums) {
       vector<int> temp1,temp2;
       int n=nums.size();
       if(n==1) return nums[0];
       for (int i = 0; i <n; i++)
       {
        if(i!=0) temp1.push_back(nums[i]);
        if(i!=n-1) temp2.push_back(nums[i]);
       }
        return max(solve(temp1),solve(temp2));
    }
};