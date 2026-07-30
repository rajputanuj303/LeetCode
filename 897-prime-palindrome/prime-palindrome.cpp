class Solution {
public:
    
    bool isPrime(long long n) {
        if (n < 2) return false;

        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    bool isPalindrome(long long n){
        long long original = n;
        long long rev = 0;

        while (n) {
            rev = rev * 10 + n % 10;
            n /= 10;
        }

        return rev == original;
    }

    int primePalindrome(int n) {       

        long long i = n;

        while(true){
            if (10000000 <= i && i < 100000000) {
                i = 100000000;
                continue;
            }
            if(isPrime(i) && isPalindrome(i)) return i;
            i++;
        }
    
        return -1;
    }
};