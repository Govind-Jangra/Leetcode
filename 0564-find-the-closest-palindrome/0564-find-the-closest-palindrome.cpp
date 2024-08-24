class Solution {
public:
    string makePalindromic(string s) {
        for (int i = 0, j = (int)s.length() - 1; i < j; i++, j--)
            s[j] = s[i];
        return s;
    }
    
    string nearestPalindromic(string n) {
        if (n == "0")
            return "1";
        
        long long orgVal = stoll(n);
    
        string res = makePalindromic(n);
        long long resVal = stoll(res);
        long long diff = abs(resVal - orgVal);
    
        long long scale = (long long)pow(10, (int)n.length() / 2);
    
        string smaller = makePalindromic(to_string((orgVal / scale) * scale - 1));
        string bigger = makePalindromic(to_string((orgVal / scale) * scale + scale));

        long long smallerVal = stoll(smaller);
        if (diff == 0 || abs(orgVal - smallerVal) <= diff) {
            res = smaller;
            diff = abs(orgVal - smallerVal);
        }

        long long biggerVal = stoll(bigger);
        if (abs(orgVal - biggerVal) < diff)
            res = bigger;
    
        return res;
    }
};