class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
         sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        int l = 0, r = n - 1, M = 1e9 + 7;
      int m=1e9+7;
     vector<int> pows(n,1);
     for(int i=1;i<n;i++){
         pows[i]=(pows[i-1]*2)%m;
     }
        while (l <= r) {
            if (nums[l] + nums[r] > target) {
                r--;
            } else {
                
                ans =(ans+pows[r-l])%m;
                l++;
            }
        }
        return ans;
    }
};