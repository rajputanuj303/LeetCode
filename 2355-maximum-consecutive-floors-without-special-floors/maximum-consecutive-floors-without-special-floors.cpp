class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        
        sort(special.begin(), special.end());

        int i = 0;
        int maxFloors = 0;

        while(i < special.size()){
            maxFloors = max(maxFloors, special[i] - bottom);
            bottom = special[i]+1;
            i++;
        }

        maxFloors = max(maxFloors, top - bottom + 1);

        return maxFloors;
    }
};