class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int bulls = 0;
        vector<int> freq1(10, 0), freq2(10, 0);
        for(int i = 0; i<n; i++){
            if(secret[i] == guess[i]) bulls++;
            else{
                freq1[secret[i]-'0']++;
                freq2[guess[i]- '0']++;
            }
        }
        int cows = 0;
        for(int i = 0; i<10; i++){
            cows += min(freq1[i], freq2[i]);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};