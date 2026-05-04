class Solution
{
public:
    vector<long long> mostFrequentIDs(vector<int> &nums, vector<int> &freq)
    {
        unordered_map<int, long long> mpp;
        priority_queue<pair<long long, int>> pq;

        vector<long long> ans;
        for (int i = 0; i < nums.size(); i++){

            mpp[nums[i]] += freq[i];
            pq.push({mpp[nums[i]], nums[i]});

            while (!pq.empty()) {

                pair<long long, int> p = pq.top();
                if(mpp[p.second] != p.first) pq.pop();                    
                else break;

            }
            
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};