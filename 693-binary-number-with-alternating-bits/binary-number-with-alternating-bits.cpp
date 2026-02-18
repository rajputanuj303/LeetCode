class Solution {
public:
    bool hasAlternatingBits(int n) {

        bool prevSet = false; 
        if((n&1) != 0) prevSet = true;
        n >>= 1;

        while(n){
            bool currSet = false;
            if((n&1) != 0) currSet = true;
            if(prevSet == currSet) return false;
            prevSet = currSet;
            n >>= 1;
        }
        return true;
    }
};