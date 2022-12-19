//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
     {
    //    int start=0;
    //    int end=n-1;
    //    while(start<=end){
    //         if(a[start]!=2){
    //             start++;
    //         }
    //         if(a[end]==2){
    //             end--;
    //         }
    //         if(a[start]==2 && a[end]!=2){
    //             swap(a[start],a[end]);
    //             start++;
    //             end--;
    //         }
    //    } 
    //    start=0;
    //     while(start>=end){
    //         if(a[start]==0){
    //             start++;
    //         }
    //         if(a[end]==1){
    //             end--;
    //         }
    //         if(a[start]==0&& a[end]==1){
    //             swap(a[start],a[end]);
    //         }
    //     }


    //  optimized solution 
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high){
        switch (a[mid])
        {
        case 0:
            swap(a[low++],a[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(a[mid],a[high--]);
            break;
        }
    }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends