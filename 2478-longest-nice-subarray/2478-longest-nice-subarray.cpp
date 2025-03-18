class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        
        int len = 1 ;
        int i = 0;
        
        while(i<nums.size())
        {
            int j = i + 1 ;
            
            while( j < nums.size() )
            {
                int k = i;

                while(k<j && ( (nums[j] & nums[k]) == 0) )
                k++;

                if(k == j)
                j++;
                else
                {
                    
                    len = max(len , j-i);
                    j = k;
                    break;
                }
            }
            
            len = max(len , j-i);
            if(i == j)
            i++;
            else
            i = j;
        }

        return len;
    }
};

