#include<iostream>
#include<queue>
using namespace std;
int solve(int *arr, int n, int k){
    deque<int>maxi(k);
    deque<int>mini(k);
    int sum=0;
    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty()&&arr[maxi.front()]<=arr[i])
        {
            maxi.pop_front();
        }
        while (!mini.empty() && arr[mini.front()]>=arr[i])
        {
            mini.pop_front();
        }
        maxi.push_back(i);
        mini.push_back(i);
        
    }
    sum=sum+arr[maxi.front()]+arr[mini.front()];
    cout<<sum<<endl;

    for (int i = k; i < n; i++)
    {
        while (!maxi.empty()&&i-maxi.front()>=k)
        {
            maxi.pop_front();
        }
        while (!mini.empty()&&i-mini.front()>=k)
        {
            mini.pop_front();
        }
        while (!maxi.empty()&&arr[maxi.front()]<=arr[i])
        {
            maxi.pop_front();
        }
        while (!mini.empty() && arr[mini.front()]>=arr[i])
        {
            mini.pop_front();
        }
        maxi.push_back(i);
        mini.push_back(i);
        sum=sum+arr[maxi.front()]+arr[mini.front()];
        cout<<sum<<endl;
    }
    return sum;
    
}
int main() {


    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << solve(arr, 7, k) << endl;


    return 0;
}