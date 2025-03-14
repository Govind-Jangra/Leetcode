class Solution {
public:
    bool fun(vector<int>& candies, int mi, long long &k){
        long long r = 0;
        for(int i = 0; i<candies.size();i++){
            r += (candies[i]/mi);
        }
        return r >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int mx = 0;
        for(int i: candies){
            mx = max(mx, i);
        }
        int l = 1, r = mx;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(fun(candies, m, k)){
                l = m+1;
            }
            else r = m-1;
        }
        if(l-1 > mx) return 0;
        return l-1;
    }
};