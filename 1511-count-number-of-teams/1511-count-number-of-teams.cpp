class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans=0;
        int n=rating.size();
        for(int i=1;i<n-1;i++){
            int lm=0,lg=0,rm=0,rg=0;
            for(int j=i-1;j>=0;j--){
                if(rating[j]==rating[i]) continue;
                if(rating[j]<rating[i]) lm++;
                else lg++;
            }
            for(int j=i+1;j<n;j++){
                if(rating[j]==rating[i]) continue;
                if(rating[j]<rating[i]) rm++;
                else rg++;
            }
            ans+=lm*rg +lg*rm;
        }
        return ans;
    }
};