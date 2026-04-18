class Solution {
public:
    int reverse(int n){
        int val = 0;
        while(n){
            val = val * 10 + (n%10);
            n/=10;
        }
        return val;
    }
    int mirrorDistance(int n) {
        int rev = reverse(n);
        return abs(n-rev);
    }
};