class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1e9 + 7;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            int s = 0;
            for(int j = i; j < n; j++) {
                s = (s + nums[j]) % MOD;
                ans.push_back(s);
            }
        }
        sort(ans.begin(), ans.end());
        for(int i = 1; i < ans.size(); i++) {
            ans[i] = (ans[i] + ans[i-1]) % MOD;
        }
        return (ans[right-1] - (left > 1 ? ans[left-2] : 0) + MOD) % MOD;
    }
};
