class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int n=nums.size();
        int m=nums[0].size();
        int i=0,j=n-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(binary_search(nums[mid].begin(),nums[mid].end(),target)){
                return 1;
            }
            if(nums[mid][m-1]<target) i=mid+1;
            else j=mid-1;
        }
        return 0;
    }
};