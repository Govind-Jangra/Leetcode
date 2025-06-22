class Solution {
public:
    std::vector<std::string> divideString(std::string s, int k, char fill) {
        std::vector<std::string> ans;
        
        for (int i = 0; i < s.size(); i += k) {
            std::string part = s.substr(i, k);
            if (part.size() < k) {
                part.append(k - part.size(), fill);
            }
            ans.push_back(part); }
        
        return ans; }
};