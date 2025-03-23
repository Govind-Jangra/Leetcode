#include<bits/stdc++.h>
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>> adj[n];
        for(auto i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }

        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        vector<long long> dist(n,1e15);
      vector<long long>  ways(n,0);
        dist[0]=0;
        ways[0]=1;
        long long m=1e9+7;
        pq.push({0,0});
        while(!pq.empty()){
            long long node=pq.top().second;
            long long currdist=pq.top().first;
            pq.pop();
            
            for(auto i:adj[node]){
                long long adjnode=i.first;
                long long adjdist=i.second;
                //first time arrive
                if(currdist + adjdist <dist[adjnode]){
                    dist[adjnode]=currdist+i.second;
                    pq.push({ dist[adjnode],adjnode});
                    ways[adjnode]=ways[node];
                }
                else if(currdist+adjdist==dist[adjnode]){
                    ways[adjnode]=(ways[adjnode] +ways[node])%m;
                }
            }
        }
        return ways[n-1]%m;
    }
};