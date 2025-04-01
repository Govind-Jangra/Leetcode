class Solution {
public:
    long long solve(int i,int n,vector<vector<int>>& questions,vector<long long>&dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        long long t=questions[i][0]+solve(i+questions[i][1]+1,n,questions,dp);
        long long nt=solve(i+1,n,questions,dp);
        return dp[i]=max(nt,t);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long>dp(questions.size()+1,-1);
        return solve(0,questions.size(),questions,dp);
    }
};