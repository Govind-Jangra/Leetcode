class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
       unordered_map<int,pair<int,int>> mp;
       int n=mat.size();
       int m=mat[0].size();
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mp[mat[i][j]]={i,j};
        }
       }
       vector<int> row(n+1,0),col(m+1,0);
       int c=0;
       for(int i=0;i<arr.size();i++){
        int rw=mp[arr[i]].first;
        int cl=mp[arr[i]].second;
        row[rw]++;
        col[cl]++;

        
        if(row[rw]==m) return i;
        if(col[cl]==n) return i;
        c++;
       }
       return -1;
    }
};