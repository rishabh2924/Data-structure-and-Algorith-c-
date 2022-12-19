//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        int n=S.size();
        int count=0;
        int res=0;
        for(int i=0;i<n;i++){
            if(S[i]=='['){
                count++;
            }
            else {
                count--;
                if(count<0){
                    res++;
                    count=0;
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
} 
// } Driver Code Ends