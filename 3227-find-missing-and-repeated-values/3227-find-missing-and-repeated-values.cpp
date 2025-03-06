
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        unordered_set<int> vis;
        int ansa, ansb;



        for ( auto& it : grid) {
            for ( auto & num : it) {
                if (vis.find(num) != vis.end()) {
                    ansa = num;
                }
                vis.insert(num);
            }
        }

        for (int i = 1; i <= n * n; ++i) {
            if (vis.find(i) == vis.end()) {
                ansb = i;
                break;
            }
        }

        return { ansa, ansb };
    }
};
