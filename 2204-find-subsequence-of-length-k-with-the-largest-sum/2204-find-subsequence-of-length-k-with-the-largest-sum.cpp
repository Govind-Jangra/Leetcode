class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> temp;
        for(int i=0;i<nums.size();i++){
            temp.push_back({nums[i],i});
        }

        sort(temp.begin(),temp.end(),greater<pair<int,int>>());

        vector<pair<int,int>> ans;

        for(int i=0;i<k;i++){
            ans.push_back({temp[i].second,temp[i].first});
            // cout<<temp[i].second<<" "<<temp[i].first<<endl;
        }

        sort(ans.begin(),ans.end());
        vector<int> result;
        for(auto it: ans) result.push_back(it.second);
        return result;
    }
};