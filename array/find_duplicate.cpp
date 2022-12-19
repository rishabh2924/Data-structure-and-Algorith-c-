#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int>count (nums.size(),0);
        int ans;
        for (int i = 0; i < nums.size(); i++)
        {
            count[nums[i]]++;
        }
        for (int i = 0; i < count.size(); i++)
        {
            if(count[i]>1){
                ans=i;
            }
            break;
        }
        return ans;
    }
};