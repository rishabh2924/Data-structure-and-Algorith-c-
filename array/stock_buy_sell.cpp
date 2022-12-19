#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool cmp(pair<int,int> a,pair<int,int> b){
        return a.second<b.second;
    }
    int maxProfit(vector<int>& prices) {
        // int maxi=INT_MIN;
        // int n=prices.size();
        // for (int i = 0; i < n; i++)
        // {
        //    for (int j=i; j < n; j++)
        //    {
        //      int diff=prices[j]-prices[i];
        //      maxi=max(diff,maxi);
        //    }
           
        // }
        // if(maxi<=0){
        //     return 0;
        // }
        // return maxi;
        int n=prices.size();
        int mini=0;
        int maxprofit=0;
        for (int i = 0; i < n; i++)
        {
            mini=min(mini,prices[i]);
            maxprofit=max(maxprofit,prices[i]-mini);
        }
        return maxprofit;
        
    }
};