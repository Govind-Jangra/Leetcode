class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        map<int,int>mp;
        for(int i=0;i<edges.size();i++){
            mp[edges[i][1]]++;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(mp.find(i)==mp.end()){
                ans.push_back(i);
            }
        }
        if(ans.size()==1){
            return ans[0];
        }   
        return -1;
    }
};