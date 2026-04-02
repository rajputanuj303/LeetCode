class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, n = s.size();
        int maxLen = 0, maxFreq = 0;
        unordered_map<char, int> mpp;
        while(r<n){
            mpp[s[r]]++;
            maxFreq = max(maxFreq, mpp[s[r]]);
            if((r-l+1-maxFreq) > k){
                mpp[s[l]]--;
                if(mpp[s[l]] == 0) mpp.erase(s[l]);
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};