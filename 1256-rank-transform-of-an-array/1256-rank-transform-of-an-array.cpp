class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int>m;
        for(auto it:arr){
            m[it]=0;
        }
        int rank=0;
        for(auto [k,v]:m){
            m[k]=++rank;
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=m[arr[i]];
        }
        return arr;
       
    }
};