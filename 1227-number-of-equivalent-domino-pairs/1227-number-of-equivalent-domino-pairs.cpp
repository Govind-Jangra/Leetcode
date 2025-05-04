class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> mpp;
        int n = dominoes.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int a = dominoes[i][0];
            int b = dominoes[i][1];
            pair<int, int> element = {min(a, b), max(a, b)};
            mpp[element]++;
        }

        for (auto it : mpp) {
            int freq = it.second;
            count += (freq * (freq - 1)) / 2;
        }

        return count;
    }
};