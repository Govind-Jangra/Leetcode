class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<int> res;
        for (int i = 0; i < words.size(); ++i) {
            if (res.empty() || groups[res.back()] != groups[i]) {
                res.push_back(i);
            }
        }
        vector<string> result;
        for (int idx : res) {
            result.push_back(words[idx]);
        }
        return result;
    }
};