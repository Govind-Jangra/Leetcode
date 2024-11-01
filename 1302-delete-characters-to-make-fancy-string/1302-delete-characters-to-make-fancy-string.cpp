class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            int t = ans.size();
            if (t > 1 && ans[t - 1] == s[i] && ans[t - 2] == s[i])
                continue;
            ans.push_back(s[i]);
        }
        return ans;
    }
};