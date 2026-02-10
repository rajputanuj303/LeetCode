class NumArray {
public:
    vector<int> SegTree;
    int n;

    void buildTree(int i, int l, int r, vector<int> &nums){
        if(l == r){
            SegTree[i] = nums[l];
            return;
        }

        int mid = l + (r-l)/2;

        buildTree(2*i+1, l, mid, nums);
        buildTree(2*i+2, mid+1, r, nums);

        SegTree[i] = SegTree[2*i+1] + SegTree[2*i+2];
    }

    int query(int i, int l, int r, int st, int end){
        if(r < st || l > end) return 0;
        if(l >= st && r <= end) return SegTree[i];

        int mid = l + (r-l)/2;

        int lSum = query(2*i+1, l, mid, st, end);
        int rSum = query(2*i+2, mid+1, r, st, end);
        return lSum + rSum;
    }


    NumArray(vector<int>& nums) {
        n = nums.size();
        SegTree.resize(4*n, 0);

        buildTree(0, 0, n-1, nums);
    }
    
    int sumRange(int left, int right) {
        
        return query(0, 0, n-1, left, right);

    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */