class Solution {
public:
    int maxDistance(vector<vector<int>>& nums) {
        int minn=nums[0][0];
        int maxx=nums[0].back();
        int ans=0;
        for(int i=1;i<nums.size();i++){
            ans=max({ans,abs(nums[i][0]-maxx),abs(nums[i].back()-minn)});
            minn=min(minn,nums[i][0]);
            maxx=max(maxx,nums[i].back());
        }
        return ans;
    }
};