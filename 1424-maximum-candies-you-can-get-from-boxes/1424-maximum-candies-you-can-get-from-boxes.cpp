class Solution {
public:
    int maxCandies(vector<int>& s, vector<int>& cand, vector<vector<int>>& keys, vector<vector<int>>& cb, vector<int>& initial) {
        set<int> ks;
        set<int> to_open;
        queue<int> q;
        int n=cand.size();
        vector<bool> vis(n,0);
        int ans=0;
        for(auto i:initial){
            
            q.push(i);
            vis[i]=1;
        }
        while(!q.empty()){
            int t=q.front();
            q.pop();
            if(s[t]==0 && ks.find(t)==ks.end()){
                to_open.insert(t);
                continue;
            }
            if(keys[t].size()>0){
                for(auto i:keys[t]){
                    ks.insert(i);
                }
            }
            ans+=cand[t];
            if(cb[t].size()>0){
                for(auto i:cb[t]){
                    q.push(i);
                    vis[i]=1;
                }
            }
        }
        for(auto i:to_open){
            if(ks.find(i)!=ks.end()){
                q.push(i);
            }
        }
        while(!q.empty()){
            int t=q.front();
            q.pop();
            if(s[t]==0 && ks.find(t)==ks.end()){
                continue;
            }
            if(keys[t].size()>0){
                for(auto i:keys[t]){
                    ks.insert(i);
                }
            }
            ans+=cand[t];
            if(cb[t].size()>0){
                for(auto i:cb[t]){
                    q.push(i);
                    vis[i]=1;
                }
            }
        }
        return ans;

    }
};