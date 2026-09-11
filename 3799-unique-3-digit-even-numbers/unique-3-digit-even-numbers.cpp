class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        
        int count = 0;

        vector<int> present(10, 0);

        for(int digit : digits) present[digit]++;

        for(int i = 100; i<1000; i+=2){
            
            int num = i;
            bool flag = true;
            vector<int> temp = present;
            while(num){
                if(temp[num%10] == 0){
                    flag = false;
                    break;
                }
                temp[num%10]--;
                num /= 10;
            }

            if(flag) count++;
        }

        return count;
    }
};