//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node,unordered_map<int ,bool>& visited,unordered_map<int ,bool> &dfsvisited,vector<int> adj[]){
        visited[node]=1;
        dfsvisited[node]=1;
        for(auto i: adj[node]){
            if(!visited[node]){
                bool cycle=dfs(i,visited,dfsvisited,adj);
                if(cycle){
                    return true;
                }

            }
            else if(dfsvisited[i]){
                return true;
            }
        }
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        unordered_map<int ,bool> visited;
        unordered_map<int,bool> dfsvistited;
        for(int i=0;i<V;i++){
            if(!visited[i]){
            bool ans=dfs(i,visited,dfsvistited,adj);
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

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends