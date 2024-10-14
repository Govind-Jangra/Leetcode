class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq;
        for(auto it:nums){
            pq.push(it);
        }
        long long ans=0;
        while(!pq.empty() && k--){
            auto it=pq.top();
            pq.pop();
            ans+=it;
            pq.push((it+2)/3);
        }
        return ans;
    }
};