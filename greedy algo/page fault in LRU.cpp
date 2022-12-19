//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        int count=0;
        vector<int> vec;
        for(int i=0;i<N;i++){
            auto it=find(vec.begin(),vec.end(),pages[i]);
            if(it==vec.end()){
                count++;
                if(vec.size()==C){
                    vec.erase(vec.begin());
                }
                vec.push_back(pages[i]);
            }
            else{
                vec.erase(it);
                vec.push_back(pages[i]);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
// } Driver Code Ends