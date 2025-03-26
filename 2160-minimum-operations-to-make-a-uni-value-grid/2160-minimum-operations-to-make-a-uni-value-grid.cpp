class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>nums;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                nums.push_back(grid[i][j]);
            }
        }
        int ans=0;
        int l=nums.size();
    nth_element(nums.begin(),nums.begin()+(l/2) , nums.end());
        
        int target=nums[l/2];
    for(int &num:nums){
        if(num%x != target%x) return -1;
        ans+=abs(target-num)/x;
    }
    return ans;
    }
};