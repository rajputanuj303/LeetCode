class Solution {
public:
    int maximumLengthSubstring(string s) {

        int l = 0, r = 0;
        int maxLen = 0;
        int n = s.size();
        vector<int> freq(26, 0);

        while(r < n){
            int c = s[r];
            freq[c-'a']++;
            while(freq[c-'a'] > 2){
                freq[s[l]-'a']--;
                l++;
            }

            maxLen = max(maxLen, r-l+1);
            r++;
        }

        return maxLen;
    }
};