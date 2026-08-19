class Solution {
public:
    
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {   
        
        unordered_map<int, unordered_set<int>> reserved;

        for(vector<int> v : reservedSeats){
            reserved[v[0]].insert(v[1]);
        }

        int count = 2 * (n - reserved.size());            

        for (auto &[row, seats] : reserved) {

            bool left = true;
            bool middle = true;
            bool right = true;

            for (int seat = 2; seat <= 5; seat++) {
                if (seats.count(seat)) {
                    left = false;
                    break;
                }
            }

            for (int seat = 4; seat <= 7; seat++) {
                if (seats.count(seat)) {
                    middle = false;
                    break;
                }
            }

            for (int seat = 6; seat <= 9; seat++) {
                if (seats.count(seat)) {
                    right = false;
                    break;
                }
            }

            if (left && right)
                count += 2;
            else if (left || middle || right)
                count++;
        }

        return count;
    }
};