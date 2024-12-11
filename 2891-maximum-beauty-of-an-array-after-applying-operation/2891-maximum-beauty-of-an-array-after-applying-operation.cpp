class Solution {
public:
    int solve(vector<vector<int>> LinesPair, int N) {
        
        map<int, int> m;
    for (auto& line : LinesPair) {
        m[line[0]]++;
        m[line[1] + 1]--;
    }
    int total = 0;
    int c = 0;
    for (auto& i : m) {
        c += i.second;
        total = max(total, c);
    }
    return total;
    }


        int maximumBeauty(vector<int>& nums, int k) {
            vector<vector<int>> LinesPair;


        for(int i=0;i<nums.size();i++)
        {


            LinesPair.push_back({nums[i]-k,nums[i]+k});
        }


        return solve(LinesPair,nums.size());
    }
};