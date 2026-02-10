using ll = long long;
class Solution {
public:
    vector<pair<ll, ll>> SegTree;
    vector<int> arr;

    void buildTree(int i, int l, int r){
        if(l == r){
            SegTree[i] = {arr[l], arr[l]};
            return;
        }

        int mid = l + (r-l)/2;

        buildTree(2*i+1, l, mid);
        buildTree(2*i+2, mid+1, r);

        int lmax = SegTree[2*i+1].first;
        int rmax = SegTree[2*i+2].first;
        int lmin = SegTree[2*i+1].second;
        int rmin = SegTree[2*i+2].second;
        
        SegTree[i] = {max(lmax, rmax), min(lmin, rmin)};
    }

    pair<ll, ll> Query(int i, int l, int r, int st, int end){

        if(r < st || l > end) return {LLONG_MIN, LLONG_MAX}; 
        if(l >= st && r <= end) return SegTree[i];

        int mid = l + (r-l)/2;

        pair<ll, ll> lp = Query(2*i+1, l, mid, st, end);
        pair<ll, ll> rp = Query(2*i+2, mid+1, r, st, end);


        return {max(lp.first, rp.first), min(lp.second, rp.second)};
    }
    long long countSubarrays(vector<int>& nums, long long k) {

        int n = nums.size();
        arr.resize(n);
        SegTree.resize(4*n);

        for(int i = 0; i<n; i++) arr[i] = nums[i];

        buildTree(0, 0, n-1);

        int l = 0, r = 0;
        ll subCount = 0;

        while(r < n){
            auto p = Query(0, 0, n-1, l, r);

            ll cost = (p.first - p.second)*(r-l+1);

            while(cost > k){
                l++;
                auto p = Query(0, 0, n-1, l, r);
                cost = (p.first - p.second)*(r-l+1);
            }

            subCount += (r-l+1);
            r++;
        }
        
        return subCount;
    }
};