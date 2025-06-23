using ll = long long;

class Solution {
public:
    ll sum = 0;

    int check(ll val, int k){
        string s = "";

        while(val > 0){
            ll rem = val % k;
            val /= k;
            s += to_string(rem);
        }

        int i = 0, j = s.length() - 1;
        while(i < j){
            if(s[i] != s[j]) return 0;
            i++; j--;
        }

        return 1;
    }

    void solve(ll i, ll val, ll size, ll k, int& n){
        if(n == 0) return;

        if(i >= (size + 1) / 2){
            if(check(val, k)){
                sum += val;
                n--;
            }
            return;
        }

        for(ll it = 0; it < 10; it++){
            if(val == 0 && it == 0) continue;

            ll temp = val + it * 1LL * pow(10LL, i);
            if(size - i - 1 != i)
                temp += it * 1LL * pow(10LL, size - i - 1);

            solve(i + 1, temp, size, k, n);
        }
    }

    long long kMirror(int k, int n) {
        sum = 0;
        ll len = 1;

        while(n){
            solve(0, 0, len, k, n);
            len++;
        }

        return sum;
    }
};