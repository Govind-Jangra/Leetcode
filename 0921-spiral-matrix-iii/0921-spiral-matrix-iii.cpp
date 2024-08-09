class Solution {
public:
    int m1,n1;
    void solve(vector<vector<int>>&res,int r,int c,int &ct){
        if(r>=0 && r<m1 && c>=0 && c<n1){
            {res.push_back({r,c});ct++;}
        }
    }
    vector<vector<int>> spiralMatrixIII(int m, int n, int rs, int cs) {
        
        vector<vector<int>>res;
        res.push_back({rs,cs});
        int l=cs-1,r=cs+1,t=rs-1,b=rs+1,ct=2;
        m1=m;n1=n;
        while(ct<=m*n){
            for(int i=t+1;i<b;i++) solve(res,i,r,ct);
            for(int i=r;i>=l;i--)  solve(res,b,i,ct);
            for(int i=b-1;i>t;i--) solve(res,i,l,ct);
            for(int i=l;i<=r;i++)  solve(res,t,i,ct);
            r++;l--;t--;b++;
        }
        return res;
    }
};