class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n-k+1,-1);
        int ind=-1;
        for(int i=0;i<n;i++){
            if(ind>=0 && i-k>=ind){
                ind=-1;
            }
            if(i>0 && k>1 && nums[i]!=nums[i-1]+1){
                ind=i-1;
            }
            if(i+1>=k && ind==-1){
                ans[i-k+1]=nums[i];
            }
        }
        return ans;
    }
};