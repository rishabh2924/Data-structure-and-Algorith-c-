#include<bits/stdc++.h>
using namespace std;
void dfs(int node,unordered_map<int,bool>& visited,stack<int> &st,unordered_map<int,list<int>> &adj){
    visited[node]=1;
    for(auto i:adj[node]){
        if(!visited[i]){
        dfs(i,visited,st,adj);
    }}
    st.push(node);
}
void redfs(int node,unordered_map<int,bool>& visited ,unordered_map<int,list<int>> &adj){
    visited[node]=1;
    for(auto i:adj[node]){
        if(!visited[i]){
            redfs(i,visited,adj);
        }
    }
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	unordered_map<int,list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
         
        adj[u].push_back(v);
    }
    stack<int> st;
    unordered_map<int,bool> visited;
    for (int i = 0; i < v; i++)
    {
        if(!visited[i]){
            dfs(i,visited,st,adj);
        }
    }
    //transpose of graph
    unordered_map<int,list<int> > transpose;
    for (int i = 0; i < v; i++)
    {
        visited[i]=0;
        for(auto nbr:adj[i]){
            transpose[nbr].push_back(i);
        }
    }
    //dfs 
    int count=0;
    while(!st.empty()){
        int top=st.top();
        st.pop();
        if(!visited[top]){
            redfs(top,visited,transpose);
        }
    }
    return count;
}