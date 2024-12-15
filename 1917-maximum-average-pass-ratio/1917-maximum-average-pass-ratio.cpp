class Solution {
public:
    
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto f = [&](double p, double t) { return (p + 1) / (t + 1) - p / t; };
        double r = 0; priority_queue<tuple<double, int, int>> q;
        for (auto x: classes) r += (double) x[0] / x[1],
            q.push({f(x[0], x[1]), x[0], x[1]});
        while (extraStudents--) {
            auto [d, p, t] = q.top(); q.pop();
            r += d; q.push({f(p + 1, t + 1), p + 1, t + 1});
        }
        return r / classes.size();
    }
};