//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
       int n=str.length();
       unordered_map<char,int >map;
       for(int i=0;i<n;i++){
        map[str[i]]=0;
       }
       int count =0;int ans=INT_MAX;
       int j=0;
       int i=0;
       while (j<n)
       {
         if(map[str[j]]==0) count++;
         map[str[j]]++;
         if(count==map.size()){
            while(i<j && map[str[i]]>1){
                map[str[i]]--;
                i++;
            }
            ans=min(ans,j-i+1);
         }

       }
       return ans;
    }

};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends