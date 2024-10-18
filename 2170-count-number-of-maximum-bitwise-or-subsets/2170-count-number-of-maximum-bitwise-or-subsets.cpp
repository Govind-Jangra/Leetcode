class Solution {
public:
    void solve(int i,vector<int>& nums,int mx,int curr,int &ans){
        if(i==nums.size()){
            ans+=(mx==curr);
            return;
        }
        solve(i+1,nums,mx,curr|nums[i],ans);
        solve(i+1,nums,mx,curr,ans);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int mx=0;
        for(auto it:nums){
            mx|=it;
        }
        int ans=0;
        solve(0,nums,mx,0,ans);
        return ans;
    }
};