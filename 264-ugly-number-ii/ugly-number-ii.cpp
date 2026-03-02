class Solution {
public:
    int nthUglyNumber(int n) {
        

        set<long long> stt;

        stt.insert(1);

        while(--n){

            long long val = *stt.begin();
            stt.erase(stt.begin());

            stt.insert(val*2);
            stt.insert(val*3);
            stt.insert(val*5);

        }

        return *stt.begin();
    }
};