class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        for(int i=0;i<s.size();i++){
            int x=0;
            for(int j=0;j<goal.size();j++){
                if(s[(i+j)%n]==goal[j]) x++;
            }
            if(x==n) return 1;
        }
        return 0;
    }
};