class Solution {
public:
    int solve(int i, vector<vector<int>>& jobs, vector<int>& dp) {
        if(i >= jobs.size()) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        // Binary search to find next non-overlapping job
        int low = i + 1;
        int high = jobs.size() - 1;
        int nextIndex = jobs.size();
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(jobs[mid][0] >= jobs[i][1]) {
                nextIndex = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        int take = jobs[i][2] + solve(nextIndex, jobs, dp);
        int notTake = solve(i + 1, jobs, dp);
        
        return dp[i] = max(take, notTake);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = startTime.size();
        vector<vector<int>> jobs;
        
        for(int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end()); // sort by start time
        
        vector<int> dp(n, -1);
        
        return solve(0, jobs, dp);
    }
};