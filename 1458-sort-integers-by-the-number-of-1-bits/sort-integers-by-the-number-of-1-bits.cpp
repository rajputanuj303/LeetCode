class Solution {
public:
    static bool cmp(int a, int b) {
        int setCount1 = __builtin_popcount(a);
        int setCount2 = __builtin_popcount(b);

        if(setCount1 == setCount2){
            return a < b;
        }
        return setCount1 < setCount2;
    }
    vector<int> sortByBits(vector<int>& arr) {

        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};