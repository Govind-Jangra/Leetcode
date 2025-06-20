class Solution {
public:
    int maxDistance(string s, int k) {
        int ans=0;
        for(char hr:{'E','W'}) {
            for(char vr:{'N','S'}){
                int x=0,y=0,kk=k;
                for(auto it:s){
                    if(it==hr && kk){
                        kk--;
                        it=(it=='E')?'W':'E';
                    }
                    else if(it==vr && kk){
                        kk--;
                        it=(it=='N')?'S':'N';
                    }

                        x+=it=='E';
                        x-=it=='W';
                        y+=it=='N';
                        y-=it=='S';
                        ans=max(ans,abs(x)+abs(y));
                }
            }
        }
        return ans;
    }
};