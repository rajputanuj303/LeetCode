class Solution {
public:
    int rotatedDigits(int n) {

        int count = 0;

        for(int i = 1; i <= n; i++){

            int num = i;
            bool good = false;
            while(num){

                int digit = num%10;

                if(digit == 3 || digit == 4 || digit == 7){
                    good = false;
                    break;
                }
                if(digit == 2 || digit == 5 || digit == 6 || digit == 9){
                    good = true;
                }
                num /= 10;
            }

            if(good) count++;
        }
        return count;
    }
};