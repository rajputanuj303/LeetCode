class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> res;

        vector<int> freq(10, 0);

        for(int i : digits) freq[i]++; 

        for(int i = 100; i<1000; i++){
            
            int num = i;
            vector<int> temp = freq;            
            bool flag = true;

            while(num){
                int digit = num % 10;

                if(temp[digit] <= 0){
                    flag = false;
                    break;
                }

                temp[digit]--;
                num /= 10;
            }
            
            if(flag && (i&1) == 0) res.push_back(i);
        }

        return res;
    }
};