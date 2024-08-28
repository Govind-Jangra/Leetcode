class Solution {
public:
    void bfs(int i, int j, vector<vector<int>>& v, vector<vector<int>>& grid1, vector<vector<int>>& grid2, int m, int n, bool& f) {
        queue<pair<int, int>> q;
        q.push({i, j});
        v[i][j] = 1;

        if (!grid1[i][j]) f = false;

        while (!q.empty()) {
            int row = q.front().first, col = q.front().second;
            q.pop();

            for (int r = -1; r <= 1; r++) {
                for (int c = -1; c <= 1; c++) {
                    if (abs(r) != abs(c)) {
                        int nr = row + r, nc = col + c;

                        if ((nr >= 0 && nr < m) && (nc >= 0 && nc < n) && !v[nr][nc] && grid2[nr][nc] == 1) {
                            v[nr][nc] = 1;
                            q.push({nr, nc});

                            if (!grid1[nr][nc]) f = false;
                        }
                    }
                }
            }
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size(), n = grid2[0].size(), c = 0;
        vector<vector<int>> v(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1 && !v[i][j]) {
                    bool f = true;
                    bfs(i, j, v, grid1, grid2, m, n, f);
                    if (f) c++;
                }
            }
        }

        return c;
    }
};
