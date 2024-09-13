class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        for (int i = 1; i < arr.size(); i++) {
            arr[i] ^= arr[i - 1];
        }

        vector<int> res;
        res.reserve(queries.size());

        for (auto& q : queries) {
            int L = q[0], R = q[1];
            if (L > 0) {
                res.push_back(arr[R] ^ arr[L - 1]);
            } else {
                res.push_back(arr[R]);
            }
        }

        return res;
    }
};