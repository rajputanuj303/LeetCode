class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int m = nums1.size();
        int n = nums2.size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;


        pq.push({nums1[0]+nums2[0], 0, 0});
        set<pair<int, int>> stt; 

        vector<vector<int>> res;

        while(!pq.empty()){  

            if(res.size() == k) return res;
            vector<int> v = pq.top();
            int i = v[1], j = v[2];
            pq.pop();

            if(stt.count({i, j})) continue;
            stt.insert({i, j});

            res.push_back({nums1[i], nums2[j]});

            if(i+1 < m){
                pq.push({nums1[i+1]+nums2[j], i+1, j});
            }
            if(j+1 < n){
                pq.push({nums1[i]+nums2[j+1], i, j+1});
            }
        }

        return res;
    }
};