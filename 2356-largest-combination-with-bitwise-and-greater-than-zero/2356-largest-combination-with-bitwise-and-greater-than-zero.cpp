class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxi = 0;
        for (int i = 0; i <= 24; i++) {
            int count = 0; 
            for (auto x : candidates) {
                if (x & (1 << i)) 
                    count++;
            }
            maxi = max(maxi, count); 
        }
        return maxi;
    }
};