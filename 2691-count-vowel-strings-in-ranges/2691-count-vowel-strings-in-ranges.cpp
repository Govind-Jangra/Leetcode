class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
    vector<int> points(n, 0); 

    string vowels = "aeiou";
    for (int i = 0; i < n; i++) {
        if (vowels.find(words[i][0]) != string::npos && vowels.find(words[i].back()) != string::npos) {
            points[i] = 1; 
        }
    }

    
    vector<int> prefix(n, 0);
    prefix[0] = points[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + points[i]; 
    }

    vector<int> ans(queries.size(), 0);
    for (int i = 0; i < queries.size(); i++) {
        int start = queries[i][0];
        int end = queries[i][1];

        
        int sub = (start > 0) ? prefix[start - 1] : 0; 
        ans[i] = prefix[end] - sub; 
    }
    return ans; 

        
    }
};