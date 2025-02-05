class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        unordered_map<char,int> mp;
        // int index=0;
        vector<int>index;
        int count=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                index.push_back(i);
                count++;
            }
            
        }
        if (index.size() == 0) {
            return true;
        }
        if (index.size() == 2) {
            int i = index[0], j = index[1];
            return s1[i] == s2[j] && s1[j] == s2[i];
        }
        return false;
         
    }
};