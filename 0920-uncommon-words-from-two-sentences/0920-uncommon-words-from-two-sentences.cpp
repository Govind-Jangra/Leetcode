class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int>mp1;

        int i = 0;
        while(i < s1.size()){
            string temp = "";
            while(s1[i] != ' ' && i < s1.size()){
                temp += s1[i];
                i++;
            }
            mp1[temp]++;
            i++;
        }
        i = 0;
        while(i < s2.size()){
            string temp = "";
            while(s2[i] != ' ' && i < s2.size()){
                temp += s2[i];
                i++;
            }
            mp1[temp]++;
            i++;
        }
        vector<string>ans;
        for(auto i : mp1){
            if(mp1[i.first] == 1)
            ans.push_back(i.first);
        }
        return ans;
    }
};