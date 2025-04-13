class Solution {
public:
   int mod = 1e9+7;
    long long pow(int x, long long n) {
        if(n == 0)
            return 1;
        long long xx = pow(x, n/2);
        if(n % 2 == 0)
            return (xx * xx) % mod;
        else
            return (((xx * xx) % mod) * x) % mod;
    }
    
    int countGoodNumbers(long long n) {
     
        return (pow(5, (n + 1) / 2) * pow(4, n / 2)) % mod;
    }
};