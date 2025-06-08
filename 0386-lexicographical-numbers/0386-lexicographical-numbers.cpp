class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> arr(n);
        while(n--) arr[n] = n + 1;
        sort(arr.begin(), arr.end(), [](int a, int b){return to_string(a) < to_string(b);});
        return arr;
    }
};