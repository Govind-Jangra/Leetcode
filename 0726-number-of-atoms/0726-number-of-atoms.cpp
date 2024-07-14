class Solution {
public:
   void solve(string& s, map<string, int>& mp) {
        int n = s.size();
        
        stack<int> st; 
        st.push(1);
        
        string atom; 
        int factor = 1; 
        
        for (int i = 0; i < n; ++i) {
            auto c = s[i];
            if (isdigit(c)) { 
                int val = 0;
                int  ex = 1;
                do {
                    val += (c - '0') * ex;
                    ++i; ex *= 10;
                } while (isdigit(c = s[i]));
                factor = val;
                
                i -= 1;
            } else if (c == ')') { 
                st.push(factor * st.top());
                factor = 1; 
            } else if (c >= 'A' && c <= 'Z') {
                atom += c;
                reverse(atom.begin(), atom.end());
                mp[atom] += factor * st.top();
                factor = 1;
                atom.clear();
            } else if (c >= 'a' && c <= 'z') {
                atom += c;
            } else { 
                st.pop();  
                
            } 
        }   
    }
    string countOfAtoms(string s) {
       map<string, int> mp;
        reverse(s.begin(), s.end());
        solve(s, mp);
        string ans;
        
        for (auto it : mp) {
            ans += it.first;
            if (it.second > 1) {
                ans += to_string(it.second);
            }
        }
        return ans;
    }
    

 
};