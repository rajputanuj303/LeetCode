class Solution {
public:

    bool isPermutation(int x, int y){
        vector<int> freq(10, 0);


        while(x){
            freq[x%10]++;
            x /= 10;
        }
        while(y){
            freq[y%10]--;
            y /= 10;
        }

        for(int i : freq){
            if(i != 0) return false;
        }
        return true;
    }


    bool isDigitorialPermutation(int n) {

        vector<int> fact(10, 0);
        fact[0] = 1;

        for(int i = 1; i<10; i++){
            fact[i] = i * fact[i-1];
        }

        int temp = n;
        int sum = 0;

        while(temp){
            sum += fact[temp%10];
            temp /= 10;
        }
        
        return isPermutation(sum, n);
    }
};