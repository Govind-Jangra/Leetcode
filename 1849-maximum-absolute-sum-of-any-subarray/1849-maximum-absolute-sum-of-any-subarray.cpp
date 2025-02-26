class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans=0;
        int mx=0,mn=0;
        for(auto it:nums){
            ans+=it;
            mx=max(mx,ans);
            mn=min(mn,ans);
        }
        return  mx-mn;
    }
};