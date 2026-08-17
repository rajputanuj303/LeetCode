class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        
        multiset<int> maxHeap;

        // cout << *maxheap.rbegin() << endl;;

        int n = chargeTimes.size();
        int l = 0, r = 0;
        int maxRange = 0;
        long long rangeSum = 0;

        while(r < n){

            maxHeap.insert(chargeTimes[r]);
            rangeSum += runningCosts[r];

            long long currVal = *maxHeap.rbegin() + (1LL*(r-l+1)*rangeSum);

            if(currVal <= budget){
                maxRange = max(maxRange, r-l+1);
                
            }else{
                maxHeap.erase(maxHeap.find(chargeTimes[l]));
                rangeSum -= runningCosts[l];
                l++;
            }
            r++;
        }

        return maxRange;
    }
};