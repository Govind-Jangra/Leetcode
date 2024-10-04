class Solution {
public:
    long long dividePlayers(vector<int>& nums) {
        long long ans=0;
        // 1 2 3 3 4 5 
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int curr=nums[0]+nums[n-1];
        // cout<<curr<<" "; 
        int i=1,j=n-2;
        ans+=nums[0]*nums[n-1];
        while(i<j){
            int t=nums[i]+nums[j];
            // cout<<t<<" ";
            if(t!=curr) return -1;
            ans+=nums[i]*nums[j];
            i++;
            j--;
        }
        return ans;
    }
};