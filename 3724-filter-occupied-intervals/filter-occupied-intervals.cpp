class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    }

    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals,
                                                int freeStart, int freeEnd) {
        if (occupiedIntervals.empty()) return {};

        sort(occupiedIntervals.begin(), occupiedIntervals.end(), cmp);

        vector<vector<int>> result;

        int l = occupiedIntervals[0][0];
        int r = occupiedIntervals[0][1];

        auto process = [&](int s, int e) {
            if (e < freeStart || s > freeEnd) {
                result.push_back({s, e});
            } else {
                if (s < freeStart)
                    result.push_back({s, freeStart - 1});
                if (e > freeEnd)
                    result.push_back({freeEnd + 1, e});
            }
        };

        for (int i = 1; i < occupiedIntervals.size(); i++) {
            if (occupiedIntervals[i][0] <= r + 1) {
                r = max(r, occupiedIntervals[i][1]);
            } else {
                process(l, r);
                l = occupiedIntervals[i][0];
                r = occupiedIntervals[i][1];
            }
        }

        process(l, r);

        return result;
    }
};