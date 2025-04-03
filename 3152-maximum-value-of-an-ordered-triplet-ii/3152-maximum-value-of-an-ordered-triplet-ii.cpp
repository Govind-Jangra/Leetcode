class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<long long> left(n,0);
        vector<long long> right(n,0);
        
        int maxx=nums[0];
        for(int i=0;i<n;i++)
        {
            left[i]=maxx;
            maxx=max(maxx,nums[i]);
        }
        
        maxx=nums[n-1];
        for(int i=n-1;i>=0;i--)
        {
            right[i]=maxx;
            maxx=max(maxx,nums[i]);
            
        }
        long long ans=0;
        for(int i=1;i<n-1;i++)
        {
            ans=max(ans,(left[i]-(long long)nums[i])*right[i]);
        }
        return ans;
    }
};