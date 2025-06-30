class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans=0;
        sort( nums.begin(),nums.end());
        int i=0;
        for(int j=0;j<nums.size();j++){
            while(nums[j]-nums[i]>1) i++;
            if(nums[j]-nums[i]==1) ans=max(ans,j-i+1);
        }
        return ans;
    }
};