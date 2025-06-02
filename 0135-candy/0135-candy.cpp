class Solution {
public:
    int candy(vector<int>& s) {
        int n=s.size();
        if(n==1) return 1;
        vector<int> dp(n,1);
        for(int i=1;i<n;i++)
        {
            if(s[i]>s[i-1]) dp[i]=dp[i-1]+1;
        }
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]>s[i+1]) dp[i]=max(dp[i+1]+1,dp[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++) ans+=dp[i];
        return ans;
    }
};