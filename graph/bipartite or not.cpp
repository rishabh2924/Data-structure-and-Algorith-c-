//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool check(vector<int>& color,int node,vector<int> adj[]){
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(auto nbr:adj[temp]){
                if(color[nbr]==0){
                    color[nbr]=!color[temp];
                     q.push(nbr);
                }
                else if(color[nbr]==color[temp]){
                    return false;
                }
        }
        
        }
        return true;}
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
        vector<int> color(V,0);
        for(int i=0;i<V;i++){
            if(color[i]==0){
                if(!check(color,i,adj)){
                    return false;
                }
            }
        }
        return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends