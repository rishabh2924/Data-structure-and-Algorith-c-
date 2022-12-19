#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int breakpoint = -1;
        for (int i = nums.size() - 1; i > 0; i--)
        {
            if (nums[i - 1] < nums[i])
            {
                breakpoint = i - 1;
                break;
            }
        }
        if (breakpoint == -1)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            for (int i = nums.size() - 1; i > breakpoint; i--)
            {
                if (nums[i] > nums[breakpoint])
                {
                    swap(nums[i], nums[breakpoint]);
                    reverse(nums.begin() + breakpoint+1, nums.end());
                    break;
                }
            }
        }
    }
};