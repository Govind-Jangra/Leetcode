#define pii pair<int,int>
#define ff first
#define ss second

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> adj[n+1];
        vector<int> seen(n+1);
        const int MAX_VISIT=70;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<pii>q;
        q.push({0,1});
        seen[1]++;
        int mn=INT_MAX;
        while(q.size()){
            auto it=q.front();q.pop();
            int cost=it.ff;
            int node=it.ss;
            for(auto nbr:adj[node]){
                if(seen[nbr]>70){
                    continue;
                }
                int newcost=cost+time;
                if(((cost/change)&1)){
                   newcost=newcost+(change-(cost%change));   
                }
                if(nbr==n){
                    
                    if(newcost!=INT_MAX and newcost>mn){
                        return newcost;
                    }
                    else if(newcost<mn){
                        mn=newcost;
                    }
                }
                q.push({newcost,nbr});
                seen[nbr]++;
            }
        }
        return mn;
    }
};