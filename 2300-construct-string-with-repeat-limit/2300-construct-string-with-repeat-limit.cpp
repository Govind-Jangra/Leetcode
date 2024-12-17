class Solution {
public:
    string repeatLimitedString(string s, int limit) { 
       sort(s.rbegin() , s.rend());
       int n =s.size();
       char prev=s[0];
       int count=0;
       string ans;
       for(int i =0;i<n;i++)
       {
          if(s[i]==prev)
          { 
            count++;
            if(count>limit)
            {
                int swapInd=i;
                int nextInd=findNext(s, i + 1, n - 1, prev);;
                if(nextInd==-1)
                return ans;
                swap(s[swapInd], s[nextInd]);
            }
          }
          else
        count=1;
          prev = s[i];
          ans.push_back(s[i]);
       }
       return ans;
    }
    int findNext( string & s, int low, int high, char prev) {
        int result = -1;
        while (low <= high) {
            int mid = low +(high - low)/2;
            if (s[mid]<prev) {
                result = mid; 
                high = mid -1;
            } else {
                low = mid +1; 
            }
        }
        return result;
    }
};                                                                                                                                                                                                                                                     