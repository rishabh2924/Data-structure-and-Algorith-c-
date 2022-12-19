//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define N 1000

// } Driver Code Ends
// you are required to complete this function
// function should print the required range
class node
{
public:
    int data;
    int row;
    int col;
    node(int d, int r, int c)
    {
        data = d;
        row = r;
        col = c;
    }
};
class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }

}; 
class Solution
{
public:
    pair<int, int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        priority_queue<node*, vector<node*>, compare> minheap;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for (int i = 0; i < n; i++)
        {
           int ele=KSortedArray[i][0];
             mini=min(mini,ele);
            maxi=max(maxi,ele);
            minheap.push(new node(ele,i,0));
        }
        int start=mini;
        int end=maxi;
        while (minheap.size()>0)
        {
            node* temp=minheap.top();
            minheap.pop();
            mini=temp->data;

            if(maxi-mini<start-end){
                start=mini;
                end=maxi;
            }
            if(temp->col+1<N){
                node* next=new node(KSortedArray[temp->row][temp->col+1],temp->row,temp->col+1);
                maxi=max(maxi,next->data);
                minheap.push(next);
            }
            else break;
        }
        return {start,end};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[N][N];
        pair<int, int> rangee;
        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        rangee = obj.findSmallestRange(arr, n, k);
        cout << rangee.first << " " << rangee.second << "\n";
    }
    return 0;
}

// } Driver Code Ends