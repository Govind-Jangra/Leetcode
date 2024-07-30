class Solution {
public:
    int minimumDeletions(string s) {
        int b=0;
        
        int n=s.size();
        int ans=0;
        for(auto it:s){
            if(it=='a') ans=min(1+ans,b);
            else b++;
        }
        return ans;

    }
};