//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool operat(char c){
            if(c=='+'|| c=='-'|| c=='*'|| c=='/'){
                return true;
            }
            return false;
        }
    int checkRedundancy(string s) {
        // code here
        
        stack<char> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('|| operat(s[i])){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                if(operat(st.top())){
                    while(st.top()!='('){
                        st.pop();
                    }
                    st.pop();
                }
                else{
                    return true;
                }
            }  
        }
        return false;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends