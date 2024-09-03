class Solution {
public:
    vector<int> minimumRangeSlidingWindow(vector<pair<int,int>> &nums, int k) {
        int ans = INT_MAX;
        unordered_map<int,int> mp;
        int c = 0;
        int i = 0;
        int n = nums.size();
        int j = 0;
        vector<int> temp(2);
        temp[0]=-1e9;
        temp[1]=1e9;
        
        while (j < n) {
            mp[nums[j].second]++;
            if (mp[nums[j].second] == 1) c++;
            
            while (i <= j && c == k) {
                if (abs(temp[0] - temp[1]) > abs(nums[i].first - nums[j].first)) {
                    temp = {nums[i].first, nums[j].first};
                }
                
                if (--mp[nums[i].second] == 0) c--;
                i++;
            }
            j++;
        }
        return temp;
    }

    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>> temp;
        int n = nums.size();
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        
        for (int i = 0; i < n; i++) {
            pq.push({nums[i][0], {0, i}});
        }
        
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int val = it.first;
            int ind = it.second.first;
            int group = it.second.second;
            temp.push_back({val, group});
            
            if (ind + 1 < nums[group].size()) {
                pq.push({nums[group][ind+1], {ind+1, group}});
            }
        }
        
        return minimumRangeSlidingWindow(temp, nums.size());
    }
};
