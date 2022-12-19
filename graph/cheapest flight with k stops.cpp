#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//this method will give TLE....................----------



//-----------------------------------------------
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector< pair<int,int> > > adjList;
	for( auto flight : flights )
		adjList[flight[0]].push_back( { flight[1], flight[2] } );

	/* BFS starting from src */
	queue< pair<int,int> > q; // < node, dist_from_src > pair
	q.push( { src, 0 } );
	int srcToTgtDist = INT_MAX; // result

	while( !q.empty() && k-- >= 0 ) {
		int size = q.size();
		for( int i = 0; i < size; i++ ) {
			auto curr = q.front(); q.pop();         
			for( auto nbr : adjList[curr.first] ) {
				if( srcToTgtDist < curr.second + nbr.second ) continue;

				q.push( { nbr.first, curr.second + nbr.second } );

				// update distance from src to dst
				if( dst == nbr.first ) 
					srcToTgtDist = min( srcToTgtDist, curr.second + nbr.second );
				}
		}
	}
	return srcToTgtDist == INT_MAX ? -1 : srcToTgtDist;
    }

    //--------------------------bellman ford method--------------------
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         vector<int> dist(n,1e8);
        dist[src]=0;
        for(int i=0;i<=k;i++){
           vector<int> temp(dist);
            for(auto nbr:flights){
                if(dist[nbr[0]]!=1e8){
                    temp[nbr[1]]=min(temp[nbr[1]],dist[nbr[0]]+nbr[2]);
                }
            }
            dist=temp;
        }
        return dist[dst]==1e8?-1:dist[dst];
    }
};