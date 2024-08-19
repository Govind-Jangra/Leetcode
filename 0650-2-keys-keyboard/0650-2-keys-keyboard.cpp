class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        int ans = 0;
        int f = 2;
        while (n > 1) {
            while (n % f == 0) {
                ans += f;
                n /= f;
            }
            f++;
        }
        
        return ans;
    }
};