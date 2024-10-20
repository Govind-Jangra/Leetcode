class Solution {
public:
  bool solvenot(string &s,int &i)
  {
      i+=2;
      bool it=solve(s,i);
      i++;
      return !it;
  }
  bool solveor(string &s,int &i)
  {
      i+=2;
      bool ans=0;
      ans|=solve(s,i);
      while(s[i]!=')')
        {
            i++;
            ans|=solve(s,i);
        }
        i++;
        return ans;
  }

   bool solveand(string &s,int &i)
  {
      i+=2;
      bool ans=1;
      ans&=solve(s,i);
      while(s[i]!=')')
        {
            i++;
            ans&=solve(s,i);
        }
        i++;
        return ans;
  }

  
   bool solve(string &s,int &i)
   {
       if(s[i]=='t')
       {
           i++;
           return 1;
       }
       if(s[i]=='f')
       {
           i++;
           return 0;
       }
       if(s[i]=='&')
        return solveand(s,i);
        if(s[i]=='|')
        return solveor(s,i);
        if(s[i]=='!')
         return solvenot(s,i);
       return 1;  

   }
    bool parseBoolExpr(string expression) {
        int i=0;
        return solve(expression,i);
    }
};