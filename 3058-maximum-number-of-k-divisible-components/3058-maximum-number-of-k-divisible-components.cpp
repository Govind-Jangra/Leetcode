class Solution {
public:
    long long ans=0;
    long long K;
    long long solve(long long node,long long parent,vector<int> adj[],vector<int>& values)
    {
        long long sum=values[node];
        for(auto it:adj[node])
        {
            if(it==parent) continue;
            sum+=solve(it,node,adj,values);
        }
        if(sum%K==0){
            ans++;
            return 0;
        }
        return sum;
    }
    long long maxKDivisibleComponents(long long n, vector<vector<int>>& edges, vector<int>& values, long long k) {
        vector<int> adj[n];
        K=k;
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        long long z=solve(0,-1,adj,values);
        return ans;
    }
};