//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        unordered_map<string,int> map;
        int maxi=0;
        string s="";
        for(int i=0;i<n;i++){
            map[arr[i]]++;
            if(map[arr[i]]>maxi){
                maxi=map[arr[i]];
                s=arr[i];
            }
        }
        map[s]=0;
        s="";
        for(int i=0;i<n;i++){
            if(map[arr[i]]>maxi){
                maxi=map[arr[i]];
                s=arr[i];
            }
        }
        return s;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends