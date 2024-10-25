class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string>ans;
        unordered_map<string, int>mp;
        sort(folder.begin(), folder.end());
        for(auto s: folder)
        {
            if(mp.find(s) == mp.end())
            {
                string x = "";
                bool flag = 0;
                int i = 1;
                while(i<s.length())
                {
                    x += '/';
                    while(i<s.length() && s[i] != '/')
                    {
                        x += s[i];
                        i++;
                    }
                    if(mp.find(x) != mp.end())
                    {
                        flag = 1;
                        break;
                    }
                    i++;
                }
                
                if(!flag)
                {
                    mp[s]++;
                }
                i++;
            }
        }
        for(auto s: mp)
            ans.push_back(s.first);
        return ans;
    }
};

