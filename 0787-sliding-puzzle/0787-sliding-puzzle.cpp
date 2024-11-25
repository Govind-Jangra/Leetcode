class Solution {
public:
   int slidingPuzzle(vector<vector<int>>& board) {
       
        string end = "123450";
        vector<vector<int>> moves = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
      
        
        string s = "";
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                s+=to_string(board[i][j]);
            }
        }
        unordered_set<string> st;
        st.insert(s);
        queue<pair<string, int>> q;
        q.push({s, 0});
        while(!q.empty()) {
            auto it = q.front(); q.pop();
            string curr = it.first;
            int ans = it.second;
            int idx = curr.find("0");
            if(curr == end)
                return ans;
            for(auto &i : moves[idx]) {
                string temp = curr;
                swap(temp[idx], temp[i]);
                if(!st.count(temp)) {
                    st.insert(temp);
                    q.push({temp, ans + 1});
                }
            }
        }
        return -1;
    }
	
};
