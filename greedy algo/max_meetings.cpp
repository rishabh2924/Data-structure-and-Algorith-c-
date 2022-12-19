//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    static bool cmp(pair<int,pair<int,int>>a,pair<int,pair<int,int>>b){
        return a.second.second<b.second.second;
    }
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<pair<int,pair<int,int> > >meeting;
       for(int i=0;i<N;i++){
        pair<int,pair<int,int>>p= make_pair(i+1,make_pair(S[i],F[i]));
        meeting.push_back(p);
       }
       sort(meeting.begin(),meeting.end(),cmp);
       vector<int>ans;
        ans.push_back(meeting[0].first);
        int ansend=meeting[0].second.second;
        for (int i = 1; i < N; i++)
        {
            if(meeting[i].second.first>ansend){
                ans.push_back(meeting[i].first);
                ansend=meeting[i].second.second;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends