class Solution {
public:
bool solve(vector<int>& nums, int k,int m)
{
    int c=0;
    int prev=-2;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]<=m && prev!=i-1)
        {
            c++;
            prev=i;
        }
    }
    return c>=k;
}
    
    int minCapability(vector<int>& nums, int k) {
       
        int i=1e9;
        int j=0;
        for(auto it:nums )
        {
            i=min(i,it);
            j=max(j,it);
        }

        int ans=0;
        while(i<=j)
        {
            int m=(i+j)/2;
            if(solve(nums,k,m))
            {
                ans=m;
                j=m-1;

            }
            else i=m+1;
        }
        return ans;
    }
};
