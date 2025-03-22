class Solution {
public:
    void dfs(int curr, vector<int> adj[], int n, vector<bool>& vis, int& a, int& b) {
        vis[curr] = true;
        a++;
        b += adj[curr].size();
        for (auto e : adj[curr]) {
            if (!vis[e]) {
                dfs(e, adj, n, vis, a, b);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<bool> vis(n, false);

        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int x = 0, y = 0;
                dfs(i, adj, n, vis, x, y);
                ans += (x * (x - 1)) == y;
            }
        }

        return ans;
    }
};