class Solution {
public:
    pair<int,string> solve(string s,string r,int c){
        stack<char> st;
        int ans=0;
        for(auto it:s){
            if(!st.empty() && st.top()==r[0] && it==r[1]){
                ans+=c;
                st.pop();
            }
            else st.push(it);
        }
        string t="";
        while(!st.empty()){
            t+=st.top();
            st.pop();
        }
        reverse(t.begin(),t.end());
        return {ans,t};
    }
    int maximumGain(string s, int x, int y) {
        string ab="ab",ba="ba";
        if(x<y){
            swap(x,y);
            swap(ab,ba);
        }
        auto it1= solve(s,ab,x);
        auto it2=solve(it1.second,ba,y);
        return it1.first+it2.first;
    }
};