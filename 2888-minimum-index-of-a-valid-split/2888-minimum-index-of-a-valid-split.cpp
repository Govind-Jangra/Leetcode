class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int x=0;
        unordered_map<int,int> m;
        int f=0;
        int n=nums.size();
        for(auto i:nums) {
                m[i]++;
                if(m[i]*2>n) {
                        f=m[i];
                        x=i;
                }
        }
        
        int f1=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==x) f1++;

            if( f1*2>(i+1) && (f-f1)*2>(n-i-1) ) return i;
        }
        return -1;
        
    }
};