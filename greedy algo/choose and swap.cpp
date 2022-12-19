//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
  string chooseandswap(string a){
        // Code Here
        vector<int> first(26,-1);
       int n=a.size();
       for(int i=0;i<n;i++){
        if(first[a[i]-'a']==-1){
            first[a[i]-'a']=i;
        }
       }
       int i,j=0;
       for( i=0;i<n;i++){
        bool flag =false;
        for( j=0;j<a[i]-'a';j++){
            if(first[j]>first[a[i]-'a']){
                flag=true;
                break;
            }
        }
        if(flag) break;
       }
      
if (i < n-1) {
     char ch1=a[i];
       char ch2=char(j+'a');
       for( i=0;i<n;i++){
        if(a[i]==ch1){
            a[i]=ch2;
        }
        else if(a[i]==ch2){
            a[i]=ch1;
        }
           }}
       return a;
    }
    
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}

// } Driver Code Ends