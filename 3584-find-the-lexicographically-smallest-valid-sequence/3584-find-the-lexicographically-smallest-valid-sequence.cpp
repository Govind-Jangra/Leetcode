class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
    int len1 = word1.size(), len2 = word2.size();
    int skipCount = 0;
    
    vector<int> lastIndex(len2, -1);
    
    for (int i = len1 - 1, j = len2 - 1; i >= 0; --i) {
        if (j >= 0 && word1[i] == word2[j]) {
            lastIndex[j--] = i;
        }
    }
    
    vector<int> result;
    
    for (int i = 0, j = 0; i < len1 && j < len2; ++i) {
        bool canSkip = (skipCount == 0 && (j == len2 - 1 || i < lastIndex[j + 1]));
        
        if (word1[i] == word2[j] || canSkip) {
            result.push_back(i);
            skipCount += (word1[i] != word2[j++]);
        }
    }
    
    return (result.size() == len2) ? result : vector<int>();
  }

};