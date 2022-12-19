//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        int count0=0;
        int count1=0;
        int maxcount=0;
        int i=0;
        while(i<str.size()){
            if(str[i]=='1') count1++;
            else count0++;
            i++;
            if(str[i]==str[i-1]){
              if(str[i]=='1') count1++;
            else count0++;  
            i++;
            }
            if(count0>0 && count1>0 &&count0==count1){
                maxcount++;
                count0=0;
                count1=0;
            }
        }
        if(!maxcount){
            return -1;
        }
        return maxcount;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends