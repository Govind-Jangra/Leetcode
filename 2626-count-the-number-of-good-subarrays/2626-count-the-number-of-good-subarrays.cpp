class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans=0;
        int i=0;
        int j=0;
        int n= nums.size();
        unordered_map<int,int> mp;
        int curr=0;
        while(j<n) {
            curr+=mp[nums[j]];
            mp[nums[j]]++;
            while(curr>=k){
                ans+=n-j;
                curr-=mp[nums[i]]-1;
                mp[nums[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};