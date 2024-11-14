class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        priority_queue<pair<int, pair<int, int>>> pq;
        for (int x : quantities) n--, pq.push({x, {x, 1}}); 
        while (n--) {
            auto x = pq.top().second;
            auto [a, b] = x; b++;
            pq.pop();
            pq.push({(a + b - 1) / b, {a, b}});
        }
        return pq.top().first;
    }
};