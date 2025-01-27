#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int total_k = count(nums.begin(), nums.end(), k);
        int max_gain = 0; // Initialize with 0 to account for v == k case

        for (int v = 1; v <= 50; ++v) {
            if (v == k) continue; // Skip v == k as handled by initializing max_gain to 0

            int current_max = INT_MIN;
            int max_so_far = INT_MIN;
            for (int num : nums) {
                int val = (num == v) ? 1 : (num == k ? -1 : 0);
                if (current_max == INT_MIN) {
                    current_max = val;
                } else {
                    current_max = max(val, current_max + val);
                }
                max_so_far = max(max_so_far, current_max);
            }
            if (max_so_far > max_gain) {
                max_gain = max_so_far;
            }
        }

        return total_k + max_gain;
    }
};