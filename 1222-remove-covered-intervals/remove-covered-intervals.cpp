class Solution {
public:
    static bool cmp(vector<int> &v1, vector<int> &v2){
        if(v1[0] == v2[0]) return v1[1] > v2[1];
        return v1[0] < v2[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), cmp);

        int mini = intervals[0][0];
        int maxi = intervals[0][1]-1;

        int count = n;

        for(int i = 1; i<n; i++){

            int currMini = intervals[i][0];
            int currMaxi = intervals[i][1]-1;

            if(currMini >= mini && currMaxi <= maxi) count--;
            else{
                mini = currMini;
                maxi = currMaxi;
            }
        }

        return count;
    }
};