//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string S)
{
    int n=S.size();
    int count0=0;
    int count1=0;
    for(int i=0;i<n;i++){
        if(i%2==0 && S[i]=='1' || i%2!=0 && S[i]=='0'){
            count0++;
        }
        if(i%2==0 && S[i]=='0' || i%2!=0 && S[i]=='1'){
            count1++;
        }
    }
    return min(count0,count1);
}