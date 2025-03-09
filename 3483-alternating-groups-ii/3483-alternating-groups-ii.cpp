class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        vector<int> temp(nums.begin(), nums.end()); 
        for(auto it:nums) temp.push_back(it);
        int i=1,j=0;
        while(n>(i-k) && j<n){
            if(temp[i - 1]!=temp[i]) i++;
            else j=i,i++;
            if((i-j)>= k) j++,ans++;
        }     
        return ans;
    }
};
