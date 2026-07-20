class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        
        unordered_map<int, int> mpp;

        for(int i : barcodes){
            mpp[i]++;
        }

        priority_queue<pair<int, int>> pq;

        for(pair<int, int> p : mpp){
            pq.push({p.second, p.first});
        }

        int i = 0;

        while(!pq.empty()){
            pair<int, int> c1 = pq.top();
            pq.pop();

            barcodes[i++] = c1.second;
            
            if(!pq.empty()){
                pair<int, int> c2 = pq.top();
                pq.pop();

                barcodes[i++] = c2.second;
                if(c2.first-1) pq.push({c2.first-1, c2.second});
            }
            if(c1.first-1) pq.push({c1.first-1, c1.second});
        }

        return barcodes;
    }
    
};