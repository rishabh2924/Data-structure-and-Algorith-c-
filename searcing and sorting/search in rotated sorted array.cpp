#include<bits/stdc++.h>
using namespace std;
int findpivot(int s,int e ,vector<int>&nums){
    while(s<e){
        int mid=s+(e-s)/2;
        if(nums[0]<=nums[mid]){
            s=mid+1;
        }
        else e=mid;
    }
    return s;
}
int bs(int s,int e,vector<int> & nums,int target){
    while(s<=e){
        int mid=s+(e-s)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            e=mid-1;
        }
        else s=mid+1;
    }
    return -1;
}
int search(vector<int>& nums, int target) {
    int s=0;
    int n=nums.size();
    int e=n-1;
    int pivot =findpivot(s,e,nums);
    if(target>=nums[pivot]&& target<=nums[e]){
        return bs(pivot,e,nums,target);
    }
    else 
    return bs(s,pivot-1,nums,target);
    }