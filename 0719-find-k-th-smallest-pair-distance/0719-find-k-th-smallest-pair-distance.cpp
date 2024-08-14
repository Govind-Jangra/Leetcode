class Solution {
public:
    bool solve(vector<int>& nums, int k,int mid)
    {
        int c=0;
        int j=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            while(j<n && nums[j]-nums[i]<=mid) j++;
            c+=j-i-1;
        }
        return c>=k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        int n=nums.size();
        int j=nums[n-1]-nums[0];
        int ans=0;
        while(i<=j)
        {
            int m=(i+j)/2;
            if(solve(nums,k,m))
            {
                j=m-1;
                ans=m;
            }
            else i=m+1;
        }
        return ans;
    }
};