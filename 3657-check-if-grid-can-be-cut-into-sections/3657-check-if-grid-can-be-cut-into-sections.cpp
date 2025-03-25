class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> x_coords, y_coords;

        for (const auto& rect : rectangles) {
            x_coords.emplace_back(rect[0], 1);
            x_coords.emplace_back(rect[2], -1);
            y_coords.emplace_back(rect[1], 1);
            y_coords.emplace_back(rect[3], -1);
        }

        sort(x_coords.begin(), x_coords.end());
        sort(y_coords.begin(), y_coords.end());

        return countSections(x_coords) >= 3 || countSections(y_coords) >= 3;
    }

    int countSections(const vector<pair<int, int>>& coords) {
        int sections = 0, overlap = 0;

        for (const auto& coord : coords) {
            overlap += coord.second;
            if (overlap == 0) {
                sections++;
            }
        }

        return sections;
    }
};