class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int currMax=nums[0];
        for(int i=1;i<n;i++){
            ans=max(ans,nums[i]-i+currMax);
            currMax=max(currMax,nums[i]+i);
        }
        return ans;
    }
};