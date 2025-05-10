class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) { 
        long long sum1 = 0, sum2 = 0;
        int z1 = 0, z2 = 0; 
        for(int n : nums1){
            if(n == 0)z1++;
            sum1 += n;
        }
        for(int n : nums2){
            if(n == 0)z2++;
            sum2 += n;
        } 
        if(z1 == 0 && z2 == 0) return sum1 == sum2 ? sum1 : -1;
        else if(z1 == 0) return sum2 + z2 <= sum1 ? sum1 : -1;
        else if (z2 == 0) return sum1 + z1 <= sum2 ? sum2 : -1; 
        return max(sum1 + z1, sum2 + z2);
    }
};