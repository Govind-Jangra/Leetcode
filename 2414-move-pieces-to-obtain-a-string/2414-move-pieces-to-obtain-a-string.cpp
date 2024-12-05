class Solution {
public:
    bool canChange(string start, string target) {

        int s1=0;
        int s2=0;

        while(s1<start.size()||s2<target.size())
        {

            if(start[s1]=='_')
            {
                s1++;
            }
            else if(target[s2]=='_')
            {
                s2++;
            }
            else{

                if(start[s1]!=target[s2])return false;
                if(start[s1]=='R'&&s1>s2)return false;
                if(start[s1]=='L'&&s1<s2)return false;
                s1++;
                s2++;
            }

        }
        return s1==s2;
        
    }
};