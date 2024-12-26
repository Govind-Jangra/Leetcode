class Solution {
public:
    int solve(int i,int n,int sum,vector<int>& nums, int target,vector<vector<int>> &dp)
    {
        if(i==n)
        {
            if(sum==target) return 1;
            return 0;
        }
        if(dp[i][sum+1000]!=-1) return dp[i][sum+1000];
        int l=solve(i+1,n,sum+nums[i],nums,target,dp);
        int r=solve(i+1,n,sum-nums[i],nums,target,dp);
        return dp[i][sum+1000]=l+r;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(2005,-1));
        return solve(0,nums.size(),0,nums,target,dp);
    }
};