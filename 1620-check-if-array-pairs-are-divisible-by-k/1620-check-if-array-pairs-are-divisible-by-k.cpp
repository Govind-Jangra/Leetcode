class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        cout<<(-33)%2;
        vector<int> rem(k,0);
        for(auto it:arr) rem[(((it)%k)+k)%k]++;
        if(rem[0]%2) return 0;
        for(int i=1;i<k;i++){
            if(rem[i]!=rem[k-i]) return 0;
        }
        return 1;
    }
};