class Solution {
public:
    int n;
    vector<vector<pair<int, int>>> dp;
    pair<int, int> Solver(int idx, bool Alice, vector<int> &nums){

        if(idx >= n) return {0, 0};
        if(dp[idx][Alice].first != INT_MIN) return dp[idx][Alice];
            
        pair<int, int> best = {INT_MIN, INT_MIN};

        int sum = 0;
        for(int i = idx; i<n && i < idx+3; i++){
            sum += nums[i];
            pair<int, int> next = Solver(i+1, !Alice, nums);

            if(Alice){  
                if(sum + next.first > best.first){
                    best = {sum + next.first, next.second};
                }
            }else{
                if(sum + next.second > best.second){
                    best = {next.first, sum + next.second};
                }
            }
        }

        return dp[idx][Alice] = best;
    }
    string stoneGameIII(vector<int>& stoneValue) {

        n = stoneValue.size();        
        dp.assign(n+1, vector<pair<int, int>>(2, {INT_MIN, INT_MIN}));
        pair<int, int> res = Solver(0, 1, stoneValue);

        if(res.first == res.second) return "Tie";
        else if(res.first > res.second) return "Alice";
        else return "Bob";
    }
};