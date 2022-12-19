//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps()
    void solve(string str,string &max,int position,int k){
        if(k==0){
            return ;
        }
        int maxi=str[position];
        for(int i=position;i<str.length();i++){
            if(maxi<str[i])
            maxi=str[i];
        }
        if(maxi!=str[position]){
            k--;
        }
        for(int i=str.length()-1;i>=position;i--){
            if(str[i]==maxi){
                swap(str[position],str[i]);
                if(str.compare(max)>0){
                    max=str;
                }
                solve(str,max,position+1,k);
                swap(str[position],str[i]);
            }
        }
    }
    
    string findMaximumNum(string str, int k)
    {
       // code here.
       string max=str;
       solve(str,max,0,k);
       return max;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends