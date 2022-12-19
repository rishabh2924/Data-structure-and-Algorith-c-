#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool isposible(int x,int y,int n,int m,int color,int start){
    if(x<0|| x>=n|| y<0|| y>=m|| ){
        return false;
    }
    return true;
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int n=image.size();
        int m=image[0].size();
        
        int start=image[sr][sc];
        while(!q.empty()){
            pair<int,int> front=q.front();
            q.pop();
            int x=front.first;
            int y=front.second;
            
            if(isposible(x-1,y,n,m)&& image[x-1][y]==start){
                q.push({x-1,y});
                image[x-1][y]=color; 
                
            }
            if(isposible(x,y+1,n,m)&& image[x][y+1]==start){
                q.push({x,y+1});
                image[x][y+1]=color; 
                
            }
            if(isposible(x+1,y,n,m)&& image[x+1][y]==start){
                q.push({x+1,y});
                image[x+1][y]=color; 
                
            }
            if(isposible(x,y-1,n,m)&& image[x][y-1]==start){
                q.push({x,y-1});
                image[x][y-1]=color; 
                
            }
        }
        return image;
    }
};