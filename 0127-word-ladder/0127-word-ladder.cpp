class Solution {
public:
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
         queue<pair<string,int>> q;
        q.push({startWord,1});
        unordered_set<string> st;
        for(auto i: wordList){
            st.insert(i);
        }
        
        if(st.find(startWord)!=st.end()){
            st.erase(startWord);
        }
        while(!q.empty()){
            string s=q.front().first;
            int t=q.front().second;
            q.pop();
            if(s==targetWord) return t;
            
            for(int i=0;i<s.size();i++){
                char old=s[i];
                for(char ch ='a';ch<='z';ch++){
                    s[i]=ch;
                    if(st.find(s)!=st.end()){
                        q.push({s,t+1});
                        st.erase(s);
                    }
                }
                s[i]=old;
            }
        }
        return 0;
    }
};