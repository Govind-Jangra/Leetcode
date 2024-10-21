class Solution {
public:
    void solve(string &s,int i,unordered_set<string> &st,int &maxCount,int currCount){
        int n=s.size();

        if(i>=n) { // Base Case
            maxCount =max(maxCount,currCount);
            return;
        }

        // Below condition is not necessay needed but it gives slight improvement
        if(currCount + n-i <= maxCount) return;

        for(int j=i;j<n;j++){

            string sub=s.substr(i,j-i+1);
            if(st.find(sub)==st.end()){
                st.insert(sub);
                solve(s,j+1,st,maxCount,currCount+1);
                st.erase(sub);
            }
        }


    }
    int maxUniqueSplit(string s) {
        
        unordered_set<string> st;
        int maxCount=0;
        int currCount=0;
        int i=0;

        solve(s,0,st,maxCount,currCount);
        return maxCount;
    }
};