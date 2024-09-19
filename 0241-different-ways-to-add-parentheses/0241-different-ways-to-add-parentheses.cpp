class Solution {
    vector<int> solve(string s,int i,int j){
        if(i>j){
            return {};
        }
        if(j-i <=1){
           string num = s.substr(i, j + 1); 
           return  {stoi(num)};
        }
        vector<int>ans;
        for(int k=i; k<j; k++){
            if(s[k] == '+' || s[k] == '-' || s[k] == '*'){
                vector<int> a=solve(s,i,k-1);
                vector<int> b=solve(s,k+1,j);
                for(int p=0; p< a.size(); p++){
                    for(int q=0; q< b.size(); q++){
                        if(s[k]=='+'){
                            ans.push_back(a[p]+b[q]);
                        }
                        else if(s[k]=='-'){
                            ans.push_back(a[p]-b[q]);
                        }
                        else{
                            ans.push_back(a[p]*b[q]);
                        }
                    }
                }
            }
        }
        return ans;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression,0,expression.size()-1);
    }
};