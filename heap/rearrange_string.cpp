//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
struct key{
    int freq;
    char ch;

    bool operator<(const key& k) const
    {
        return freq < k.freq;
    }
};
class Solution
{
    public:
    string rearrangeString(string str)
    {
        priority_queue<key> pq;
        int N =str.length();
       char word[26]={0};
       for ( int i = 0; i < N; i++)
       {
        word[str[i]-'a']++;
       }
        for (char c = 'a'; c <= 'z'; c++) {
        int val = c - 'a';
        if (word[val]) {
            pq.push(key{ word[val], c });
        }
    }
       
       string s=" ";
        key prev{-1,'#'};
        while (!pq.empty())
        {
           key temp=pq.top();
           pq.pop();
           s=s+temp.ch;
           if(prev.freq>0){
            pq.push(prev);
           }
           (temp.freq)--;
           prev=temp;
        }
       return s; 
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
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}
// } Driver Code Ends