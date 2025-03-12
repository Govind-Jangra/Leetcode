class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int a=0,b=0;
        int low=0; int high= nums.size()-1;
        while (low<=high){
            int mid= low+ (high-low)/2;
            if (nums[mid]<0){
                a= mid;
                low= mid+1;
            }
            else high= mid-1;
        }
        if (nums[0]!=0)a++;
        low=0; high= nums.size()-1;
        while (low<=high){
            int mid= low+(high-low)/2;
            if (nums[mid]>0){
                b= mid;
                high= mid-1;
            }
            else low= mid+1;
        }
        if (!(b==0 && nums[0]<=0 ))b= nums.size()-b;
        return max(a,b);
    }
};