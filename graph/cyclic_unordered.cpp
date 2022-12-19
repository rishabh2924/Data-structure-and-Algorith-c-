//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool dfs(int node,int parent,unordered_map<int,bool> &visited,vector<int> adj[]){
    visited[node]=1;
    for(auto i:adj[node]){
        if(!visited[node]){
           bool cyclic= dfs(i,node,visited,adj);
           if(cyclic) return true;
        }
        else if(i!=parent){
            return true;
        }
    }
    return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int,bool> visited;
        for(int i=0;i<V;i++){
            if(!visited[i]){
            bool ans=dfs(i,-1,visited,adj);
            if(ans){
                return true;
            }
            }

        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends