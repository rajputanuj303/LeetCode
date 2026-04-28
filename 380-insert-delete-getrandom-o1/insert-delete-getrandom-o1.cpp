class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> mpp;

    RandomizedSet() {}

    bool insert(int val) {
        if(mpp.count(val)) return false;

        nums.push_back(val);
        mpp[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if(!mpp.count(val)) return false;

        int idx = mpp[val];
        int last = nums.back();

        nums[idx] = last;
        mpp[last] = idx;

        nums.pop_back();
        mpp.erase(val);

        return true;
    }

    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};