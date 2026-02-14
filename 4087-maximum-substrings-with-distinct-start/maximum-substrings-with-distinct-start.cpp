class Solution {
public:
    int maxDistinct(string s) {
        vector<bool> freq(26, 0);

        for(char c : s) freq[c-'a'] = 1;

        int cnt = 0;

        for(bool b : freq){
            if(b) cnt++;
        }

        return cnt;
    }
};