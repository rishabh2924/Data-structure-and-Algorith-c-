//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool isvowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    void solve(int index,string str,set<string> &ans,string s){
        
        if(index>=s.length()){
            if(str.length()>=2){
                if(isvowel(str[0]) && !isvowel(str[str.size()-1]))
                  ans.insert(str);
            }
            return ;
        }
        solve(index+1,str+s[index],ans,s);
        solve(index+1,str,ans,s);


    }
    set<string> allPossibleSubsequences(string S){
        set<string> ans;
        string str="";
        solve(0,str,ans,S);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        set<string> ans = ob.allPossibleSubsequences(S);
        if (ans.size() == 0)
            cout << -1 << endl;
        else {
            for (auto i : ans) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends