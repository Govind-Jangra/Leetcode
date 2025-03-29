class Solution {
public:
    int solve(int n)
{
        int cnt=0;
        if(n%2==0)
        {
            cnt++;
            while (n % 2 == 0)
            {
                n = n/2;
            }
        }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        if(n%i==0)
        {
            cnt++;
            while (n % i == 0)  n = n/i;
        }
        
    }
 
    if (n > 2) cnt++;
        return cnt;
}
    int mod=1e9+7;
    
    
    
    int XPowY(int x, int y)
    {
        if (y == 0)
            return 1;
        long p = XPowY(x, y / 2) % mod;
        p = (p * p) % mod;
        return y % 2 ? (p * x) % mod : p;
    }
    int maximumScore(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<int> prime(n);
        for(int i=0;i<n;i++)
        {
            prime[i]=solve(nums[i]);
        }
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++) pq.push({nums[i],i});
        
        
        long long ans=1;
        while(k>0)
        {
            int maxi=pq.top().first;
            int ind=pq.top().second;
            int i=ind-1;
            pq.pop();
            int maxcount=prime[ind];
            long long cnt1=0;
            
            while(ind<n && prime[ind]<=maxcount)
            {
                cnt1++;
                ind++;
            }
            long long cnt2=1;
            while(i>=0  && prime[i]<maxcount )
            {
                cnt2++;
                i--;
            }
            long long take=min((long long)k,cnt1*cnt2);
            k-=take;
            ans=(ans*XPowY(maxi,take))%mod;
            if(k==0) break;
        }
        return ans;
    }
};