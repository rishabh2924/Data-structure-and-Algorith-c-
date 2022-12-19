//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    void topsort(stack<int> &st,vector<int> &vis,int i,vector<int> adj[]){
        vis[i]=1;
        for(auto nbr:adj[i]){
            if(!vis[nbr]){
                topsort(st,vis,nbr,adj);
            }
        }
        st.push(i);
    }
    void redfs(int top,vector<int> &vis,vector<int> transpose[]){
        vis[top]=1;
        for(auto i:transpose[top]){
            if(!vis[i]){
            redfs(i,vis,transpose);}
        }
    }
    int kosaraju(int V, vector<int> adj[])
    {
       stack<int> st;
       vector<int> vis(V,0);
       for(int i=0;i<V ;i++){
        if(vis[i]==false){
            topsort(st,vis,i,adj);
        }
       }
       vector<int> transpose[V];
       for(int i=0;i<V;i++){
        vis[i]=0;
        for(auto nbr:adj[i]){
            transpose[nbr].push_back(i);
        }
       }
       int count=0;
       while(!st.empty()){
        int top=st.top();
        st.pop();
        if(!vis[top]){
            count++;
            redfs(top,vis,transpose);
        }
       }
       return count;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends