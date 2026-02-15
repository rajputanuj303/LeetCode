class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for(int i : nums) mpp[i]++;

        unordered_map<int, int> freq;

        for(pair<int, int> p : mpp){
            freq[p.second]++;
        }


        for(int i : nums){
            if(freq[mpp[i]] == 1) return i;
        }

        return -1;
    }
};