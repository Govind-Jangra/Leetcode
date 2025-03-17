

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        
        unordered_map<int,int> hello ;
        
        for (int i=0;i<nums.size();i++)
            hello[nums[i]]++ ;
        
        
        for (auto& c:hello)
            if (c.second%2==1)
                return false ;
        
        return true ;
        
    }
};