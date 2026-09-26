class Solution {
public:
    bool check(int speed, vector<int> &piles, int h){

        for(int p : piles){
            h -= (p + speed - 1) / speed;;
            if(h < 0) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {


        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        int result = INT_MAX;


        while(left <= right){

            int mid = left + (right - left)/2;

            if(check(mid, piles, h)){
                result = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }

        return result;
        
    }
};