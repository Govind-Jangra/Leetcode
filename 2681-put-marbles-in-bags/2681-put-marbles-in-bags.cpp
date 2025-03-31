class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long ans=0;
        int n=weights.size();
        vector<long long> temp;
        for(int i=0;i<n-1;i++)
        {
            temp.push_back(weights[i]+weights[i+1]);
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<k-1;i++)
        {
            ans-=temp[i];
            ans+=temp[n-2-i];
        }
        return ans;
    }
};