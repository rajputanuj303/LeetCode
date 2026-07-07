class Solution {
public:
    long long sumAndMultiply(int n) {
        
        long long removed = 0;

        long long mul = 1;
        int sum = 0;
        while(n){  
            int digit = n%10;          
            if(digit != 0){
                long long val = digit*mul;
                removed += val;
                sum += digit;
                mul *= 10;
            }
            n /= 10;            
        }
        
        return removed*sum;
    }
};