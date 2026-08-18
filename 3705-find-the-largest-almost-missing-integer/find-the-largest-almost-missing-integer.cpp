class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();
        for(int i = 0; i<=n-k; i++){
            unordered_set<int> visited;
            for(int j = i; j<i+k; j++){
                if(visited.count(nums[j]) == 0){
                    freq[nums[j]]++;
                }
                visited.insert(nums[j]);
            }
        }

        int maxElement = -1;

        for(pair<int, int> p : freq){
            if(p.second == 1 && p.first > maxElement){
                maxElement = p.first;
            }
        }
        return maxElement;
    }
};