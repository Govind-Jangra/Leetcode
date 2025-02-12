class Solution {
public:
    int sumOfDIgits(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int ans=-1;
        map<int,int> mp;
        for(auto it:nums){
            int currSum=sumOfDIgits(it);
            if(mp.find(currSum)!=mp.end()) {
                ans=max(ans,it+mp[currSum]);
                mp[currSum]=max(mp[currSum],it);
            }
            else mp[currSum]=it;
        }
        return ans;
    }
};