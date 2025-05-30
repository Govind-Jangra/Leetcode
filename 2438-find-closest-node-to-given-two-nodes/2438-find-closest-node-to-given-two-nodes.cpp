class Solution {
     
    int dfs1(vector<int>& edges, int n,int m,unordered_map<int,bool> &vis1,unordered_map<int,bool> &vis2){
          vis1[n]  = 1;
          vis2[m]  = 1;
          
          if(vis1[m] && vis2[n]) return min(n,m); 
          if(vis1[m]) return m; 
          if(vis2[n]) return n; 
          if(edges[n]!=-1 && !vis1[edges[n]] && edges[m]!=-1 && !vis2[edges[m]]){
              return dfs1(edges,edges[n],edges[m],vis1,vis2) ;
          }
          if(edges[n]!=-1 && !vis1[edges[n]] && (edges[m]==-1 || vis2[edges[m]])){
              return dfs1(edges,edges[n],m,vis1,vis2) ;
          }
          if(edges[m]!=-1 && !vis2[edges[m]] && (edges[n]==-1 || vis1[edges[n]])){
              return dfs1(edges,n,edges[m],vis1,vis2) ;
          }
          return -1;
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
      
         
        
        unordered_map<int,bool> vis1;
        unordered_map<int,bool> vis2;
        return dfs1(edges,node1,node2,vis1,vis2);
    }
};