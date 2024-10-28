class Solution {
public:
    long long longestSquareStreak(vector<int>& nums) {
        // 2 4 16 256  65536
        sort(nums.begin(),nums.end());
        long long ans=0;
        long long n=nums.size();

        for(long long i=0;i<n;i++){
            long long t=nums[i];
            long long c=1;
            while(true){
                auto it=lower_bound(nums.begin()+i+1,nums.end(),t*t);
                if(it!=nums.end() && *it==t*t){
                    c++;
                    t=t*t;
                }
                else break;
            }
            ans=max(ans,c);
        }
        return ans==1?-1:ans;
    }
};