class Solution {
public:
    
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {   
        
        unordered_map<int, int> reserved;


        for(vector<int> v : reservedSeats){
            reserved[v[0]] |= (1 << v[1]);
        }

        int count = 2 * (n - reserved.size());            

        for (auto &[row, seats] : reserved) {

            bool left = true;
            bool middle = true;
            bool right = true;

            for (int seat = 2; seat <= 5; seat++) {
                if ((reserved[row] & (1 << seat))) {
                    left = false;
                    break;
                }
            }

            for (int seat = 4; seat <= 7; seat++) {
                if ((reserved[row] & (1 << seat))) {
                    middle = false;
                    break;
                }
            }

            for (int seat = 6; seat <= 9; seat++) {
                if ((reserved[row] & (1 << seat))) {
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