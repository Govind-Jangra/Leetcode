class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        for(auto it:nums){
            if(it==1)c++;
        }
        vector<int> temp;
        for(auto it:nums) temp.push_back(it);
        for(auto it:nums) temp.push_back(it);

        int i=0;
        int x=0;
        int ans=c;
        while(i<2*n){
            if(i>=c && temp[i-c]==1) x--;
            if(temp[i]==1) x++;
            if(i>=c-1)
            ans=min(ans,c-x);
            i++;
        }
        return ans;

    }
};