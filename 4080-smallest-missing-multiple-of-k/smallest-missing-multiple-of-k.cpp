class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> stt;
        for(int i : nums) stt.insert(i);

        int i = 1;
        while(true){
            if(stt.find(k*i) == stt.end()) return k*i;
            i++;
        }
        return -1;
    }
};