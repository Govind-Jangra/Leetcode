class Solution {
public:
    long long shortestSubarray(vector<int> a, long long K) {
        long long n = a.size();
        long long ans = n + 1;
        deque<long> d;
        vector<long long> nums(a.begin(),a.end());
        for (long long i = 0; i < n; i++) {
            if (i > 0)
                nums[i] += nums[i - 1];
            if (nums[i] >= K)
                ans = min(ans, i + 1);
            while (d.size() > 0 && nums[i] - nums[d.front()] >= K){
                ans = min(ans, (long long)(i - d.front()));
                 d.pop_front();
            }
            while (d.size() > 0 && nums[i] <= nums[d.back()])
                d.pop_back();

            d.push_back(i);
        }
        return ans <= n ? ans : -1;
    }
};