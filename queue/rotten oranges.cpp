//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<int,int>> q;
        int rotten=0;
        int fresh=0;
        int n=grid.size();
        int m= grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    grid[i][j]== -1;
                   rotten++;
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int newrotten=0;
        int time=0;
        while(!q.empty()){
            time++;
            int size=q.size();
            for(int p=0;p<n;p++){
                int row=q.front().first;
                int col=q.front().second;
                // for up
                if(row-1>=0 && grid[row-1][col]==1){
                    newrotten++;
                    q.push({row-1,col});
                    grid[row-1][col]=-1;
                }
                if(row+1<n && grid[row+1][col]==1){
                    newrotten++;
                    q.push({row+1,col});
                    grid[row+1][col]=-1;
                }
                if(col-1>=0 && grid[row][col-1]==1){
                    newrotten++;
                    q.push({row,col-1});
                    grid[row][col-1]=-1;
                }
                if(col+1<n && grid[row][col+1]==1){
                    newrotten++;
                    q.push({row,col+1});
                    grid[row][col+1]=-1;
                }
                q.pop();

            }
        }
        if(fresh!=newrotten){
            return -1;
        }
        else return time;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends