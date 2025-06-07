class Solution {
public:
    string clearStars(string s) {
        int n=s.size();
        string ans="";
        vector<int>vis(n,0);
        vector<vector<int>>idx(26);
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                idx[s[i]-'a'].push_back(i);
                continue;
            }
            if(s[i]=='*'){
                for(int i=0;i<26;i++){
                    if(idx[i].size()){
                        int id= idx[i].back();
                        vis[id]=1;
                        idx[i].pop_back();
                        break;
                    }
                }
                vis[i]=1;
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]) ans+=s[i];
        }
        return ans;
    }
};