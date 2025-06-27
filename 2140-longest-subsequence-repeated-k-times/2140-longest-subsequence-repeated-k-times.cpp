class Solution {
public:
    bool isKTimes(string s, string curr, int k){
        int i=0;
        int c=0;
        for(auto  it:s){
            if(it==curr[i]) i++;
            if(i==curr.size()){
                i=0;
                c++;
            }
            if(c==k) return 1;
        }
        return 0;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        queue<string> q;
        string ans="";
        q.push("");
        while(!q.empty()){
            string c=q.front();
            q.pop();
            for(char ch='a';ch<='z';ch++){
                string next=c+ch;
                if(isKTimes(s,next,k)){
                    q.push(next);
                    ans=next;
                }
            }
        }
        return ans;
    }
};