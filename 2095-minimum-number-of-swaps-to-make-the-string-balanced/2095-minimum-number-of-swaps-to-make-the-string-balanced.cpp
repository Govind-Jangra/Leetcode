class Solution {
public:
    int minSwaps(string s) {
        int o=0,c=1;
        int ans=0;
        for(auto it:s){
            if(it=='[') o++;
            else if(o>0) o--;
        }
        
        return (o+1)/2;
    }
};