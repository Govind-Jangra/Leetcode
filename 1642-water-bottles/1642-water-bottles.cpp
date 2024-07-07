class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        int avail=numBottles/numExchange;
        int unused=numBottles%numExchange;
        while(avail>0){
            ans+=avail;
             int t=((unused+avail)%numExchange);
            avail=((avail+unused)/numExchange);
            unused=t;
        }
    return ans;
    }
};