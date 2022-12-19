//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
//   int isPalindrome(string S)
// 	{
// 	   int s=0;
//        int e=S.length();
//        while(s<=e){
//         if(S[s]!=S[e]){
//             return 0;
//         }
//         s++;
//         e--;
//        }
//        return 1;
// 	}
//     string longestPalin (string S) {
//         string res="";
//         int n=S.size();
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 bool check=isPalindrome(S.substr(i,j-i+1));
//                 if(check && j-i+1>res.size()){
//                     res=S.substr(i,j-i+1);
//                 }
//             }
//         }
//         return res;
//     }

//**********optimized approach**************
string longestPalin (string S) {
        int maxlen=1;
        int start=0;
        int n=S.length();

        if(n<2){
            return S;
        }
        for(int i=2;i<n;i++){
            int low=i-1;
            int high=i+1;
            while(high<n && S[high]==S[i]){
                high++;
            }
            while(low>=0&& S[low]==S[i]){
                low--;
            }
            while(low>=0 && high<n && S[low]==S[high]){
                low--;
                high++;
            }
            int len=high-low+1;
            if(len>maxlen){
                maxlen=len;
                start=low+1;
            }
        }
        return S.substr(start,maxlen);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends