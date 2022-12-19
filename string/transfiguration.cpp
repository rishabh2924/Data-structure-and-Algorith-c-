//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
    public:
    int transfigure (string A, string B)
    {
    	  if(A.length()!=B.length()) return -1;
    int arr[256]={0};
    for(int i=0;i<A.length();i++){
        arr[A[i]]++;
        arr[B[i]]--;
    }
     for(int i=0;i<256;i++)
       {
           if(arr[i]!=0) return -1;
       }
    int alen=A.length();
    int blen=B.length();
    int res=0;
    while(alen>=0){
        if(A[alen]!=B[blen]){
            res++;
        }else{
            blen--;
        }
        alen--;
    }
    return res;
    }
};

//{ Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}
// } Driver Code Ends