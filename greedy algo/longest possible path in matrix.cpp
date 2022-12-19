//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
int helper(int x,int y,vector<vector<int>> &matrix,int xd,int yd){
    if(x==xd && y==yd){
        return 0;
    }
    if(x<0 || x>=matrix.size() || y<0 || y>=matrix[0].size()|| matrix[x][y]==0){
            return -1e9;
        }
        matrix[x][y]=0;
        int left=1+helper(x-1,y,matrix,xd,yd);
        int right=1+helper(x+1,y,matrix,xd,yd);
        int up=1+helper(x,y+1,matrix,xd,yd);
        int down=1+helper(x,y-1,matrix,xd,yd);
        matrix[x][y]=1;
        return max({right,left,up,down});

}
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here
        if(matrix[xs][ys]==0 || matrix[xd][yd]==0) return -1;
        int ans= helper(xs,ys,matrix,xd,yd);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends