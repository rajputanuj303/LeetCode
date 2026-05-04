class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {

        int n = nums.size();

        unordered_map<int, long long> mpp;
        set<pair<long long, int>> sortedSet;

        vector<long long> res;

        for(int i = 0; i<n; i++){
            int key = nums[i];
            long long currFreq = freq[i];
            long long prevFreq = mpp[key];

            if(sortedSet.count({prevFreq, key})) sortedSet.erase({prevFreq, key});

            sortedSet.insert({prevFreq + currFreq, key});

            mpp[key] += currFreq;

            pair<long long, int> largest = *sortedSet.rbegin();
            res.push_back(largest.first);            
        }

        return res;
    }
};