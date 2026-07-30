class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int total = 0;
        int push = 1;
        while(n >= 8){
            total += (8*push);
            push++;
            n -= 8;
        }
        total += (n*push);
        
        return total;
    }
};