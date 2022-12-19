#include<bits/stdc++.h>
using namespace std;
void dfs(int node,int parent,int &timer,vector<int>& disc,vector<int> &low,unordered_map<int,bool>& vis, unordered_map<int,list<int>> &adj,vector<vector<int>>& res){
    vis[node]=1;
    disc[node]=low[node]=timer++;

    for(auto nbr:adj[node]){
        if(nbr==parent){
            continue;
        }
        if(!vis[nbr]){
            dfs(nbr,node,timer,disc,low,vis,adj,res);
            low[node]=min(low[node],low[nbr]);
            if(low[nbr]>disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                res.push_back(ans);
            }
        }
        else{
            low[node]=min(low[node],disc[nbr]);
        }
    }
    

}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int,list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
         
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int timer=0;
    vector<vector<int>> res;
    vector<int> disc(v,-1);
    vector<int> low(v,-1);
    int parent =-1;
    unordered_map<int,bool> vis;

    for (int i = 0; i < v; i++)
    {
        if(!vis[i]){
            dfs(i,parent,timer,disc,low,vis,adj,res);
        }
    }
    return res;

    
}