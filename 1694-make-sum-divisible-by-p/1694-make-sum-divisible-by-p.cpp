class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
       int ans=nums.size();
       unordered_map<int,int> mp;
       long t=0;

       for(auto it:nums){
        t+=it;
       } 
       if(t%p==0) return 0;
       long c=0;
       int rem=t%p;
       mp[0]=-1;
       for(int i=0;i<nums.size();i++){
        c+=nums[i];
        int trem=(c%p-rem+p)%p;
        if(mp.find(trem)!=mp.end()) ans=min(ans,i-mp[trem]);
        mp[c%p]=i;
       }
       if(ans==nums.size())
       return -1;
       return ans;
    }
};