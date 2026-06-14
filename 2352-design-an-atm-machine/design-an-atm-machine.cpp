class ATM {
public:
    vector<int> denoms = {20, 50, 100, 200, 500};
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
        
        for(int i = 4; i>= 0; i--){
            int cnt = min(freq[i], amount/denoms[i]);
            amount -= denoms[i]*cnt;
            res[i] += cnt;
        }

        if(amount) return {-1};

        for(int i = 0; i<5; i++){
            freq[i] -= res[i];
        }

        return res;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */