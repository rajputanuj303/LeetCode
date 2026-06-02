class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        int n = nums.size();
        
        set<int> stt;


        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        int maxi = INT_MIN;
        for(int i = 0; i<n; i++){
            minHeap.push({nums[i][0], i, 0});
            maxi = max(maxi, nums[i][0]);
        }

        int left = -1, right = -1;

        int diff = INT_MAX;

        while(true){

            vector<int> minTop = minHeap.top();
            minHeap.pop();

            int mini = minTop[0];
            int idx = minTop[1];
            int ptr = minTop[2];

            if(maxi - mini < diff){
                left = mini;
                right = maxi;
                diff = maxi - mini;
            }

            if(ptr+1 >= nums[idx].size()) break;

            maxi = max(maxi, nums[idx][ptr+1]);
            minHeap.push({nums[idx][ptr+1], idx, ptr+1});
        }
                

        
        return {left, right};
    }   
};