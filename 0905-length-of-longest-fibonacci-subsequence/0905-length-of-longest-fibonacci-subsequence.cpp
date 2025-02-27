class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]=i;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int count=2;
                int lastlast=arr[i];
                int last=arr[j];
                while(true)
                {
                    if(mp.find(lastlast+last)!=mp.end())
                    {
                        count++;
                        int z=last+lastlast;
                        lastlast=last;
                        last=z;
                    }
                    else
                    break;
                }
                ans=max(ans,count);
            }
        }
        if(ans==2)
        return 0;
        
        return ans;
    }
};