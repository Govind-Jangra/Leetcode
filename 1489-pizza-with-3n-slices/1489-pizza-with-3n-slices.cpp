class Solution {
public:
    int maxSizeSlices(vector<int>& arr) {
        int n = arr.size();
        int np = n / 3;

        vector<int> dp1(180, 0);
        vector<int> Ndp1(180, 0);
        vector<int> Ndp2(180, 0);

        for (int it = n - 2; it >= 0; --it) {
            for (int rm = 1; rm <= np; ++rm) {
                int pc = arr[it] + Ndp2[rm - 1];
                int sc = Ndp1[rm];
                dp1[rm] = max(pc, sc);
            }
            Ndp2 = Ndp1;
            Ndp1 = dp1;
        }

        vector<int> dp2(180, 0);
        vector<int> Ndp22(180, 0);
        vector<int> Ndp23(180, 0);

        for (int it = n - 1; it >= 1; --it) {
            for (int rm = 1; rm <= np; ++rm) {
                int pc = arr[it] + Ndp23[rm - 1];
                int sc = Ndp22[rm];
                dp2[rm] = max(pc, sc);
            }
            Ndp23 = Ndp22;
            Ndp22 = dp2;
        }

        return max(dp1[np], dp2[np]);
    }
};