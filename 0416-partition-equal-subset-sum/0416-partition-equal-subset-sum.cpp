class Solution {
public:
    bool solve(int i,vector<int>& nums,int x, vector<vector<int>> &dp)
    {
        if(x==0) return 1;
        if(i<0) return 0;
        if(dp[i][x]!=-1) return dp[i][x];
        bool t=0;
        if(nums[i]<=x) t=solve(i-1,nums,x-nums[i],dp);
        bool nt=solve(i-1,nums,x,dp);
        return dp[i][x]=t|nt;
    }
    bool canPartition(vector<int>& nums) {
        int t=0;
        for(auto i:nums)
        {
            t+=i;
        }
        if(t%2) return 0;
        // cout<<t/2;
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(t/2+1,-1));
        return solve(nums.size()-1,nums,t/2,dp);
    }
};