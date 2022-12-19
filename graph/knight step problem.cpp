//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
   bool isvalid(int x,int y,int N,vector<vector<int>>& visited){
        if(x<1||x>N|| y<1|| y>N || visited[x][y]!=-1){
            return false;
        }
        return true;
    }
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
        vector<vector<int>>visited(N+1,vector<int>(N+1,-1));
        int dx[] = {1, 2, 1, 2, -1, -2, -1, -2};
	    int dy[] = {2, 1, -2, -1, 2, 1, -2, -1};
        queue<pair<int,int>> q;
        q.push({KnightPos[0],KnightPos[1]});
        visited[KnightPos[0]][KnightPos[1]]=0;
        
        while(!q.empty()){
            pair<int,int> front=q.front();
            q.pop();
            
            int x=front.first;
            int y=front.second;
            
            for(int i=0;i<8;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                
                
                if(isvalid(newx,newy,N,visited)){
                    q.push({newx,newy});
                    visited[newx][newy]=1+visited[x][y];
                    
                    
                }
            }
        }
        return visited[TargetPos[0]][TargetPos[1]];
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends