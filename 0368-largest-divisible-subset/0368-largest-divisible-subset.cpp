class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n,1),hash(n,1);
        sort(arr.begin(),arr.end());
        int ans=-1;
        int last=-1;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0 && 1 +dp[j]>dp[i]){
                        dp[i]=1+dp[j];
                        hash[i]=j;
                }
            }
             if(dp[i]>ans){
               ans=dp[i];
                last=i;
            }
        }
        
        // for(int i=0;i<n;i++){
           
        // }
       vector<int> temp;
       temp.push_back(arr[last]);
       while(hash[last]!=last){
          last= hash[last];
             temp.push_back(arr[last]);

       }
       return temp;
    }
};