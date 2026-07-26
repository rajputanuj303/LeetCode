class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        

        int XOR = 0;

        for(int i : nums) XOR ^= i;

        int firstSetIdx = 0;
        while(XOR){
            if(XOR&1) break;
            firstSetIdx++;
            XOR >>= 1;
        }

        int b0 = 0, b1 = 0;

        for(int i : nums){
            if( (i & (1 << firstSetIdx)) == 0) b0 ^= i;
            else b1 ^= i;
        }

        return {b0, b1};
    }
};