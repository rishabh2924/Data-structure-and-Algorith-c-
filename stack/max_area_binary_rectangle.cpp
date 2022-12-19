//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  int area_rectangle(vector<int>& heights) 
    {
        heights.push_back(0);
        int n = heights.size();
        int area = 0;
        stack<int> idx;
        
        for(int i = 0; i < n; i++)
        {
            while(!idx.empty() && heights[idx.top()] > heights[i])
            {
                int h = heights[idx.top()];
                idx.pop();
                int l = idx.empty() ? -1 : idx.top();
                area = max(area, h * (i-l-1));
            }
            idx.push(i);
        }
        return area;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        vector<int> arr(m);
        int area =0;
        for (int  i = 0; i < m; i++)
        {
            arr[i]=M[0][i];
        }
        area=area_rectangle(arr);
        //add previous row element
        for (int  i = 0; i < n; i++)
        {
            for ( int j = 0; j < m; j++)
            {
                 if(M[i][j] != 0){
                arr[i]=M[i][j]+M[i-1][j-1];}
                else arr[i]=0;
            }
            area=max(area,area_rectangle(arr));
        }
        
        return area;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends