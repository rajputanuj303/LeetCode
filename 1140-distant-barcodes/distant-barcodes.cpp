class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {

        unordered_map<int, int> freq;
        for (int x : barcodes)
            freq[x]++;

        priority_queue<pair<int, int>> pq;
        for (auto &[num, cnt] : freq)
            pq.push({cnt, num});

        int idx = 0;

        while (pq.size() > 1) {
            auto [cnt1, num1] = pq.top();
            pq.pop();

            auto [cnt2, num2] = pq.top();
            pq.pop();

            barcodes[idx++] = num1;
            barcodes[idx++] = num2;

            if (--cnt1) pq.push({cnt1, num1});
            if (--cnt2) pq.push({cnt2, num2});
        }

        if (!pq.empty())
            barcodes[idx] = pq.top().second;

        return barcodes;
    }
};