//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
         vector<vector<int>> adj(N);
        vector<int> indegree(N,0);
        for(auto c:prerequisites){
            adj[c.second].push_back(c.first);
            indegree[c.first]++;
        }
        queue<int> q;
        vector<int> topsort;
        for(int i=0;i<N;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int top=q.front();
            q.pop();
            topsort.push_back(top);
            for(auto neig:adj[top]){
                indegree[neig]--;
                if(indegree[neig]==0){
                    q.push(neig);
                }
            }
        }
        if(topsort.size()!=N){
            return false;
        }
        return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;S
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Endsx2     