class Solution {
public:
    vector<string> getWordsInLongestSubsequence( vector<string>& words, vector<int>& groups) {    
        int n= words.size();
        vector<int> memo(n, 1);
        
        int ans = 0;
        
        vector<int> cache(n);

        int lastId = 0; 
        
        for (int i = 0; i < n; i++) {
            
            cache[i] = i;
            for (int j = 0; j < i; j++) {
                
                 if (words[i].size() != words[j].size()) continue;
                bool flag = 0;
                int t = 0;
                
                int x = 0, y = 0;
                
                int m = words[i].size();
                
               
                
                while (x < m ) {
                    if (words[i][x] != words[j][y]) {
                        t++;
                    }
                    x++;
                    y++;
                }
                
                if (t == 1 && groups[i] != groups[j] && 1 + memo[j] > memo[i]) {


                    memo[i] = 1 + memo[j];

                    cache[i] = j;
                }

            }
            
            if (ans < memo[i]) {


                ans = memo[i];


                lastId = i;
            }
        }

        vector<string> finalAns;


        finalAns.push_back(words[lastId]);

        while (cache[lastId] != lastId) {


            lastId = cache[lastId];


            finalAns.push_back(words[lastId]);
        }

        reverse(finalAns.begin(), finalAns.end());

        return finalAns;
    }
};
