class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        
        sort(special.begin(), special.end());
        
        int maxFloors = 0;

        for(int i = 0; i<special.size(); i++){
            maxFloors = max(maxFloors, special[i] - bottom);
            bottom = special[i]+1;
        }

        maxFloors = max(maxFloors, top - bottom + 1);

        return maxFloors;
    }
};