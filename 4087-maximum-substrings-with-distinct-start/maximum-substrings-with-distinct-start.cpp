class Solution {
public:
    int maxDistinct(string s) {
        vector<bool> freq(26, 0);

        int cnt = 0;

        for(char c : s){
            if(freq[c-'a'] == 0){
                cnt++;
                freq[c-'a'] = 1;
            }
        }

        return cnt;
    }
};