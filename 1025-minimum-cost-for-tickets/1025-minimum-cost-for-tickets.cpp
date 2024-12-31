class Solution {
public:
int solve(int i,vector<int>& days, vector<int>& costs,int n,vector<int> &dp){
    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];
    int take1=0;
    int take2=0;
    int take3=0;
    //-1
    take1=costs[0]+solve(i+1,days,costs,n,dp);

    //2
    int j=days[i]+7-1;
    int x=i;
    while(x<n && days[x]<=j){
        x++;
    }
    take2=costs[1]+solve(x,days,costs,n,dp);


//-3
     j=days[i]+30-1;
     x=i;
    while(x<n && days[x]<=j){
        x++;
    }
    take3=costs[2]+solve(x,days,costs,n,dp);
    
    
    return dp[i]=min({take1,take2,take3});
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n+1,-1);
        return solve(0,days,costs,n,dp);
    }
};