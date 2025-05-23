class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long minn=INT_MAX,ans=0,c=0;
        for(auto it:nums){
        
            if((it^k)>it){
                ans+=(it^k);
                minn=min(minn,(long long)((it^k)-it));
                c++;
            }
            else{
                ans+=(it);
                minn=min(minn,(long long)(it-(it^k)));
            } 
            
        }
        if(c%2==0) return ans;
        return ans-minn;
    }
};