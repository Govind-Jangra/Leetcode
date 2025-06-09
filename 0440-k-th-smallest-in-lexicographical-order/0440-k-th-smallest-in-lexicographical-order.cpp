class Solution {
public:
    int count(long curr, long nxt, int n){
        long cnt=0;
        while(curr<=n){
            cnt+=(nxt-curr);
            curr*=10;
            nxt*=10;
            nxt=min(nxt,(long)n+1);
        }
        return cnt;
    }

    int findKthNumber(int n, int k) {
        long curr=1;
        k-=1;
        while(k>0){
            long cnt=count(curr,curr+1,n);
            if(cnt<=k){
                curr++;
                k-=cnt;
            }
            else{
                curr*=10;
                k-=1;
            }
        }
        return curr;        
    }
};