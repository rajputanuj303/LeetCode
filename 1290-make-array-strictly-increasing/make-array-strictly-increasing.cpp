class Solution {
public:
    map<pair<int, int>, int> dp;

    int Solver(int i, int prev, vector<int>& arr1, vector<int>& arr2){

        if(i >= arr1.size()) return 0;

        if(dp.count({i, prev})) return dp[{i, prev}];

        int nottake = 1e9;
        int take = 1e9;

        //do not replace
        if(arr1[i] > prev){
            nottake = Solver(i+1, arr1[i], arr1, arr2);
        }

        //replace with the value greater than prev
        auto it = upper_bound(arr2.begin(), arr2.end(), prev);

        if(it != arr2.end()){
            take = 1 + Solver(i+1, *it, arr1, arr2);
        }

        return dp[{i, prev}] = min(take, nottake);
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {


        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        sort(arr2.begin(), arr2.end());

        int res = Solver(0, -1, arr1, arr2);

        return (res >= 1e9) ? -1 : res;
    }
};