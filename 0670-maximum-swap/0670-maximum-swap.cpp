class Solution {
public:
    int maximumSwap(int num) {
        string nums = to_string(num);
        int n=nums.size();
        for(int i=0;i<n;i++){
            int mx=0;
            int idx=-1;
            for(int j=n-1;j>i;j--){
                if(nums[j]>nums[i] && nums[j]>mx){
                    mx=nums[j];
                    idx=j;
                }
            }
            if(idx!=-1){
                swap(nums[i],nums[idx]);
                return stoi(nums);
            }
        }

        return num;
    }
};
