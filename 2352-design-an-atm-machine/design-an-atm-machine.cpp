class ATM {
public:
    vector<int> freq;
    ATM() {
        freq.resize(5, 0);
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i = 0; i<5; i++){
            freq[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> res(5, 0);


        int count500 = min(freq[4], amount/500);
        amount -= (count500 * 500);

        int count200 = min(freq[3], amount/200);
        amount -= (count200 * 200);

        int count100 = min(freq[2], amount/100);
        amount -= (count100 * 100);

        int count50 = min(freq[1], amount/50);
        amount -= (count50 * 50);

        int count20 = min(freq[0], amount/20);
        amount -= (count20 * 20);
        
        if(amount) return {-1};

        freq[0] -= count20;
        freq[1] -= count50;
        freq[2] -= count100;
        freq[3] -= count200;
        freq[4] -= count500;

        return {count20, count50, count100, count200, count500};
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */