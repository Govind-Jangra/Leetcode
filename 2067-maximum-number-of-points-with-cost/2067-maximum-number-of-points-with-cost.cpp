class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
    int m = points.size();
    int n = points[0].size();
    vector<long long> pts(n, 0);
    vector<long long> left(n);
    vector<long long> right(n);

    for (int i=0; i<m; ++i) {
      left[0] = pts[0];
      right[n-1] = pts[n-1];
      for (int j=1; j<n; ++j) {
        left[j] = max(pts[j], left[j-1] - 1);
        right[n-1-j] = max(pts[n-1-j], right[n-j] - 1);
      }
      for (int j=0; j<n; ++j)
        pts[j] = max(left[j], right[j]) + points[i][j];
    }
    return *max_element(pts.begin(), pts.end());
  }
};