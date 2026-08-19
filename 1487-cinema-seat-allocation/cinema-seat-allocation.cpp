class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, int> reserved;

        for (auto &v : reservedSeats)
            reserved[v[0]] |= (1 << v[1]);

        int count = 2 * (n - reserved.size());

        // Masks for seats:
        // Left   : 2,3,4,5
        // Middle : 4,5,6,7
        // Right  : 6,7,8,9
        int left   = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int middle = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int right  = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        for (auto &[row, seats] : reserved) {

            bool canLeft   = !(seats & left);
            bool canMiddle = !(seats & middle);
            bool canRight  = !(seats & right);

            if (canLeft && canRight)
                count += 2;
            else if (canLeft || canMiddle || canRight)
                count++;
        }

        return count;
    }
};