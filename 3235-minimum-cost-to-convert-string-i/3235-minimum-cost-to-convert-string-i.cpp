class Solution {
public:
    long long dp[26][26];
void solve(int start, vector<pair<int, int>> adj[]) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, start});
        dp[start][start] = 0;

        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();

            if (dist > dp[start][node]) continue;

            for (auto [child, cost] : adj[node]) {
                if (dp[start][child] > dp[start][node] + cost) {
                    dp[start][child] = dp[start][node] + cost;
                    pq.push({dp[start][child], child});
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<pair<int,int>> adj[26];
        for(int i=0;i<original.size();i++){
            adj[original[i]-'a'].push_back({changed[i]-'a',cost[i]});
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                dp[i][j]=1e18;
            }
        }
        for(int i=0;i<26;i++){
            solve(i,adj);
        }

        long long ans=0;
        for(int i=0;i<source.size();i++){
            if(source[i]!=target[i]){
                if(dp[source[i]-'a'][target[i]-'a']==1e18){
                    return -1;
                }
                ans+=dp[source[i]-'a'][target[i]-'a'];
            }
        }
        return ans;
         


    }
};