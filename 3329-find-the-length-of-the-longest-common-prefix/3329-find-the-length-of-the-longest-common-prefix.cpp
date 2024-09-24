class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> st;
        for(auto it:arr1){
            string t=to_string(it);
            string temp="";
            for(auto it2:t){
                temp+=it2;
                st.insert(temp);
            }
                   
         }
         int ans=0;
         for(auto it:arr2){
            string t=to_string(it);
            string temp="";
            for(auto it2:t){
                temp+=it2;
                if(st.find(temp)!=st.end()){
                    ans=max(ans,(int)temp.size());
                }
            }
         }
         return ans;
    }
};