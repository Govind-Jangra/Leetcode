class Solution {
    void dfs(const int cur, const vector<vector<int>>& g, vector<int>& order, int& visited) {
        if(visited&(1<<cur)) {
            return;
        }
        visited += 1<<cur;
        for(const int next : g[cur]) {
            dfs(next, g, order, visited);
        }

        order.emplace_back(cur);
    }

public:
    string smallestNumber(string pattern) {
        int n = pattern.length()+1;
        vector<vector<int>> g(n);
        for(int i = 0; i < n-1; i++) {
            if(pattern[i] == 'D') {
                g[i].push_back(i+1);
            } else {
                g[i+1].push_back(i);
            }
        }

        int visited = 0;
        vector<int> order; order.reserve(n);
        for(int i = 0; i < n; i++) {
            dfs(i,g,order,visited);
        }

        string res(n, 0);
        for(int i = 0; i < n; i++) {
            res[order[i]] = i+1 + '0';
        }

        return res;
    }
};