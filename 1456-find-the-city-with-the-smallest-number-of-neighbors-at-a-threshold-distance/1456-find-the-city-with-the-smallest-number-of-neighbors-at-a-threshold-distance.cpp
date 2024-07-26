class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        for(int i = 0; i < n; i++) dp[i][i] = 0;
        for(auto i : edges) {
dp[i[0]][i[1]] = i[2];
dp[i[1]][i[0]] = i[2];
        }

        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }

        int ans = -1; 
        int c = n;   

        for(int i = 0; i < n; i++) {
            int t = 0;
            for(int j = 0; j < n; j++) {
                if(i != j && dp[i][j] <= distanceThreshold) {
                    t++;
                }
            }
            // cout<<t<<" ";
            if(c >= t) {
                ans = i;
                c = t;
            }
        }
        
        return ans;
    }
};
