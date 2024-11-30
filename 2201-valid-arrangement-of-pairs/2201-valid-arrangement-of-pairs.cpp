class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,list<int>>adj;
        map<int,int>indeg;
        map<int,int>out;
        for(auto &i:pairs){
            adj[i[0]].push_back(i[1]);
            out[i[0]]++;
            indeg[i[1]]++;
        }

        int start=-1;
        for(auto &[node,freq]:out){
            if(out[node]-indeg[node] == 1){
                start=node;
            }
        }
        if(start==-1){
            start=pairs[0][0];
        }
        vector<int>ans;

        function<void(int)>dfs=[&](int vertex){
            while(out[vertex]){
                out[vertex]--;
                int node=adj[vertex].back();
                adj[vertex].pop_back();
                dfs(node);
            }
            ans.push_back(vertex);
            return;
        };
        
        dfs(start);

        vector<vector<int>>fin;
        for(int i=ans.size()-1;i>0;i--){
            fin.push_back({ans[i],ans[i-1]});
        }
        return fin;
    }
};