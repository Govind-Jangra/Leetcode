class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit){
    vector<pair<int, int>> numsSorted(nums.size()); 
    for (int i = 0; i < nums.size(); ++i){ numsSorted[i] = {nums[i], i}; }
    sort(numsSorted.begin(), numsSorted.end());

    vector<int> ans(nums.size());

    for (int i = 0; i < numsSorted.size(); ++i){
        int j = i;

        vector<int> indexes = {numsSorted[j].second};
        while (j + 1 < numsSorted.size() && numsSorted[j + 1].first - numsSorted[j].first <= limit){ indexes.push_back(numsSorted[++j].second); }
        sort(indexes.begin(), indexes.end());

        j = i; 
        while (j - i < indexes.size()){ 
            ans[indexes[j - i]] = numsSorted[j].first;
            ++j;
        }

        i = j - 1; 
    }

    return ans;
}
};