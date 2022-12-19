//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int solve(vector<vector<char>> &mat,string target,int i,int j,int idx,int size,int r,int c){
         int f=0;
        if(i>=0&& j>=0 && i<r && j<c && mat[i][j]==target[idx]){
           
            char temp=mat[i][j];
            idx++;
             mat[i][j]=0;
            if(size==idx){
                f=1;
            }
           else{
            f+=solve(mat,target,i+1,j,idx,size,r,c);
            f+=solve(mat,target,i,j+1,idx,size,r,c);
            f+=solve(mat,target,i-1,j,idx,size,r,c);
            f+=solve(mat,target,i,j-1,idx,size,r,c);}

           mat[i][j]=temp;
        }
        return f;
    }
    int findOccurrence(vector<vector<char> > &mat, string target){
        int r=mat.size();
        int c=mat[0].size();
        int ans;
        for (int i = 0; i < r; i++)
        {
            for(int j=0;j<c;j++){
                if(mat[i][j]==target[0]);
                ans=solve(mat,target,i,j,0,target.size(),r,c);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}

// } Driver Code Ends