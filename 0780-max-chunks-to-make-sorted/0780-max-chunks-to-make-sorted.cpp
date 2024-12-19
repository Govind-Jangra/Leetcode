class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        int c = 0;
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            c += arr[i] - i;
            if (c == 0)
                ans++;
        }
        return ans;
    }
};