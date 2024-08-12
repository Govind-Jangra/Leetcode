class Solution {
    
    int n;
    int m;
    
    vector<vector<int>> offset{{-1,0},{1,0},{0,-1},{0,1}};
    
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
        if(i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || grid[i][j] == 0) return;
        
        visited[i][j] = true;
        for(int k = 0; k < 4; k++) {
            dfs(grid, visited, i + offset[k][0], j + offset[k][1]);
        }
    }
    
    bool one_islands(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        bool found = false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 0 && !visited[i][j]) {
                    if(!found) {
                        found = true;
                        dfs(grid, visited, i, j);
                    }
                    else return false;
                }
            }
        }
        
        return true && found;
    }
    
public:
    int minDays(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        bool test = one_islands(grid);
        if(!test) return 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    bool yes = one_islands(grid);
                    if(!yes) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        
        return 2;
    }
};