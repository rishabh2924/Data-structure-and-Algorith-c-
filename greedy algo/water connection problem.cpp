//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        vector<int> iscoming(n+1,-1);
        vector<vector<int>> adjacent(n+1,vector<int>(2,-1));
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
           adjacent[a[i]][0]=b[i];
           adjacent[a[i]][1]=d[i];
           iscoming[b[i]]++;

        }
        int lastnode;
        int minvalue=INT_MAX;
        for(int i=1;i<=n;i++){
            if(iscoming[i]==-1&& adjacent[i][0]!=-1){
                lastnode=adjacent[i][0];
                minvalue=adjacent[i][1];
                while(adjacent[lastnode][0]!=-1){
                    lastnode=adjacent[lastnode][0];
                    minvalue=min(minvalue,adjacent[lastnode][1]);

                }
                ans.push_back({i, lastnode, minvalue});
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends