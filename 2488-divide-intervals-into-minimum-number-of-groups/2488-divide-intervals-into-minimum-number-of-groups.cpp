class Solution {
public:
    int minGroups(vector<vector<int>>& nums) {
        int mx = 0;
        for ( auto& it : nums) {
            mx = max(mx, it[1]); 
        }

        vector<int> temp(mx + 2, 0);
        for ( auto& it : nums) {
            temp[it[0]]++;
            temp[it[1] + 1]--;
        }

        for (int i = 1; i < mx + 2; ++i) {
            temp[i] += temp[i - 1];
        }

        int ans = 0;
        for ( auto& it : temp) {
            ans = max(ans, it);
        }

        return ans;
    }
};
