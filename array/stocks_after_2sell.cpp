//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>&price){
    int firstbuy=INT_MAX;
    int firstsell=0;
    int secondbuy=INT_MAX;
    int secondsell=0;
    for (int i = 0; i < price.size(); i++)
    {
        firstbuy=min(firstbuy,price[i]);
        firstsell=max(firstsell,price[i]-firstbuy);
        secondbuy=min(secondbuy,price[i]-firstsell);
        secondsell=max(secondsell,price[i]-secondbuy);


    }
    return secondsell;

}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends