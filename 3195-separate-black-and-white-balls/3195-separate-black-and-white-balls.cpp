class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        int j=n-1;
        long long count=0;
        long long zeros=0;
        while(j>=0){
            if(s[j]=='1'){
                count+=zeros;
            }else{
                zeros++;
            }
            j--;
        }
        return count;
    }
};