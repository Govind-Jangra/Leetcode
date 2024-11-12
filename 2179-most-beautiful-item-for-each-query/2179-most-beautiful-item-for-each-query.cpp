class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        ios_base ::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int n = items.size();
        int m = queries.size();
        vector<int>v;

        sort(items.begin(), items.end());

        for(int i = 1;i < n;i++){
            items[i][1] = max(items[i][1], items[i - 1][1]);
        }

        for(auto i : queries){
            int low = 0;
            int high = n - 1;
            int ans = 0;
            while(low <= high){
                int mid = (low + high) / 2;
                if(i >= items[mid][0]){
                    ans = items[mid][1];
                    low = mid + 1;
                }
                else high = mid - 1;
            }
            v.push_back(ans);
        }
        return v;
    }
};