//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
    //   int temp[100000]={0};
    //   int maxindex=0;
    //   for (int i = 0; i < N; i++)
    //   {
    //     temp[arr[i]]++;
    //     maxindex=max(maxindex,arr[i]);
    //   }
    //   int count=0,maxcount=0;
    //   for(int i=0;i<maxindex;i++){
    //     if(temp[i]!=0){
    //         count++;
    //     }
    //     else count =0;
    //     maxcount=max(maxcount,count);
    //   }
    //   return maxcount;

    //****************map solution*********
    unordered_map<int,int> map;
    int mini=0,maxi=0;
    for (int i = 0; i < N; i++)
    {
        map[arr[i]]=1;
        int mini=min(mini,arr[i]);
        int maxi=max(maxi,arr[i]);
    }
    int count=0, maxcount=0;
    for (int i = mini; i <= maxi; i++)
    {
        if(map.find(i)!=map.end()){
            count++;
        }
        else count =0;

        maxcount=max(count,maxcount);
    }
    return maxcount;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends