class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> marker(n + 1, 0);

        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                int left = max(0, i - k);
                int right = min(n - 1, i + k);
                marker[left]++;
                marker[right + 1]--;
            }
        }

        vector<int> result;
        int runningSum = 0;
        for (int i = 0; i < n; i++) {
            runningSum += marker[i];
            if (runningSum > 0)
                result.push_back(i);
        }

        return result;
    }
};