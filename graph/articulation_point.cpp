//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node,int parent,int & timer,vector<int> &disc,vector<int>& low,unordered_map<int,bool> &visited,vector<int>adj[],vector<int>&Ap){
        visited[node]=1;
        disc[node]=low[node]=timer++;
        int child=0;
        for(auto nbr:adj[node]){
            if(nbr==parent){
                continue;
            }
            if(!visited[nbr]){
                 
                
                dfs(nbr,node,timer,disc,low,visited,adj,Ap);
                low[node]=min(low[node],low[nbr]);
                if(low[nbr]>=disc[node]&& parent!=-1){
                   Ap[node]=1;
                }
               child++; 
            }
            else {
                low[node]=min(low[node],disc[nbr]);
            }
        }
        if(parent>-1&& child>1){
            Ap[node]=1;
        }
  }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        int timer=0;
       vector<int>ans;
       vector<int> disc(V,-1);
       vector<int> low(V,-1);
       vector<int> Ap(V,0);
       int parent=-1;
       unordered_map<int,bool> visited;
       for(int i=0;i<V;i++){
        if(!visited[i]){
        dfs(i,parent,timer,disc,low,visited,adj,Ap);
       }}
      
       for(int i=0;i<V;i++){
           if(Ap[i]){
               ans.push_back(i);
           }
       }
       if(ans.size() == 0) ans.push_back(-1);
       return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends