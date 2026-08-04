class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());

        int mini = pq.top();
        pq.pop();

        vector<int> res;

        while(!pq.empty()){
            int currMin = pq.top();
            pq.pop();

            for(int i = mini+1; i<currMin; i++){
                res.push_back(i);
            }

            mini = currMin;
        }

        return res;
    }
};