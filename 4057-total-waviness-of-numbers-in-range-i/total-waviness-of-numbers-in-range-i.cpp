class Solution {
public:
    int totalWaviness(int num1, int num2) {
        if(num2 <= 100) return 0;

        int count = 0;

        for(int num = num1; num <= num2; num++){

            int temp = num;

            while(temp){

                if(temp < 100) break;

                int threeDigits = temp%1000;
                int p3 = threeDigits%10;
                threeDigits /= 10;
                int p2 = threeDigits%10;
                threeDigits /= 10;
                int p1 = threeDigits%10;

                if(p2 > p1 && p2 > p3){
                    count++;
                }else if(p2 < p1 && p2 < p3){
                    count++;
                }  

                temp /= 10;
            }

                     
        }

        return count;
    }
};