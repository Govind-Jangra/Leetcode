class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        vector<int> ans(nums.size());
        int i = 0;
        for(int n : nums){
            if(n < pivot) 
                ans[i++] = n;  
        }
        for(int n : nums){
            if(n == pivot) 
                ans[i++] = n;  
        }
        for(int n : nums){
            if(n > pivot)
                ans[i++] = n;
        }
        return ans;
    }
};