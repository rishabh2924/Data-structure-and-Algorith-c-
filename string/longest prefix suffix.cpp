//{ Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	  int n=s.length();
      int LPS[n]={0};
      int len=0;
      int i=1;
      while(i<n){
        if(s[len]==s[i]){
            len++;
            LPS[i]=len;
            i++;
        }
        else{
            if(len>0) len=LPS[len-1];
            else{ LPS[i]=0;
            i++;
            }
        }
      }
      return LPS[n-1];
	}
};

//{ Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}

// } Driver Code Ends