class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int freq=0;
       int maj=-1;
       for(auto it:nums){
        if(freq==0){
            freq++;
            maj=it;
        }
        else if(maj==it) freq++;
        else freq--;
       }
       return maj;
    }
};