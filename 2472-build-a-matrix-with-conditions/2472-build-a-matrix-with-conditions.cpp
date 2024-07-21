class Solution {
public:
    vector<int> validorder(vector<vector<int>> &conditions, int k){
        vector<int> indegree(k+1, 0);
        vector<vector<int>> adj(k+1);
        // we will first create an adj list
        for(int i = 0 ; i< conditions.size(); i++){
            int a = conditions[i][0];
            int b = conditions[i][1];
            indegree[b]++;
            adj[a].push_back(b);
        }
        //Kahn's algo
        vector<int> order;
        queue<int> q;
        for(int i=1;i<=k;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            order.push_back(node);
            for(int i = 0 ; i<adj[node].size(); i++){
                int x=adj[node][i];
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }
        return order;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> validcol = validorder(rowConditions, k);
        vector<int> validrow = validorder(colConditions, k);

        if(validcol.size()!=k||validrow.size()!=k) return {};

        vector<vector<int>> validmatrix(k, vector<int>(k, 0));
        for(int i = 0;i<k;i++){
            for(int j = 0 ; j<k ; j++){
                if(validcol[i]==validrow[j]){
                    validmatrix[i][j]=validcol[i];
                }
            }
        }
        return validmatrix;
    }
};