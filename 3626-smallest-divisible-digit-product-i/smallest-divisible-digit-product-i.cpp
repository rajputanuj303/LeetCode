class Solution {
public:
    int smallestNumber(int n, int t) {
        
        while(true){
            int prod = 1;
            int num = n;
            while(num){
                prod *= (num%10);
                num /= 10;
            }
            if((prod % t) == 0) return n;
            n++;
        }
        return -1;
    }
};