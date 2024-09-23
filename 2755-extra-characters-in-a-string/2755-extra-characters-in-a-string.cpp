class Solution {
public:
    int solve(string& s, unordered_map<string, int>&m, vector<int>&dp, int index)
    {
        if (index >= s.size()) return 0;
        if (dp[index] != -1) return dp[index]; 
        
        string tem = "";
        int ans = s.size();
        for (int i = index; i < s.size(); i++)
        {
            tem+=s[i];
           
            int curr = m.find(tem)!=m.end()? 0 : i-index+1;
            int next = solve(s, m, dp, i + 1);
            
            
            ans = min(ans, curr+next);
        }
        return dp[index] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) 
    {
        vector<int>dp(s.size(), -1);
        unordered_map<string, int>m;
        for (string i : dictionary) m[i]++;
        
        int ans = solve(s, m, dp, 0);
        return ans;
        
    }
};